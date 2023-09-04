# select o.buyer_id, u.join_date, count(u.user_id) over(partition by u.user_id) as orders_in_2019
# from users u , orders o
# where   u.user_id = o.buyer_id and o.order_date between '2019-01-01' and '2019-12-31'

with temp as (
    select distinct(o.buyer_id), u.join_date, count(u.user_id) over(partition by u.user_id) as orders_in_2019
from users u , orders o
where   u.user_id = o.buyer_id and o.order_date between '2019-01-01' and '2019-12-31')




select  u.user_id as buyer_id, u.join_date, 
case 
when orders_in_2019 is null then 0
else  orders_in_2019  
end as orders_in_2019 
from users u
left join temp 
on u.user_id = temp.buyer_id
