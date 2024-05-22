# Write your MySQL query statement below
with c as (select 
customer_id,order_date,customer_pref_delivery_date,
row_number() over(partition by customer_id order by order_date) r,
case when order_date = customer_pref_delivery_date then 1 else 0 end as immediate
from Delivery
)

select 
round(sum(immediate)*100/count(*),2) as immediate_percentage
from c
where r = 1