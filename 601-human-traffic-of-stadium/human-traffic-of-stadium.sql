# select id,visit_date,people from (select id,visit_date,people,
#   (lead(id,1,0) over( order by visit_date)-id) as i 
#  from
# (select *,
# case
#     when people >= 100 and lead(people,1,0) over(order by visit_date)>=100 then 1
#     when people >= 100 and lead(people,1,0) over(order by visit_date)=0 then 1
#     else 0
# end as prev
# from Stadium)final
# where prev = 1
# ) t
# where i =1 or i<0 


# select id,visit_date,people from (select id,visit_date,people,  
#    count(*) over (order by visit_date
#     range between unbounded preceding AND unbounded following) as count from (select id,visit_date,people,
#   case when (lead(id,1,id) over( order by visit_date)-id) = 0 then 1
#        else (lead(id,1,id) over( order by visit_date)-id)
#    end as i 
#  from
# (select *,
# case
#     when people >= 100 and lead(people,1,0) over(order by visit_date)>=100 then 1
#     when people >= 100 and lead(people,1,0) over(order by visit_date)=0 then 1
#     when (people >= 100 and lag(people,1,0) over(order by visit_date)>=100 ) then 1
#     else 0
# end as prev
# from Stadium)final
# where prev = 1
# ) t
# where  i = 1 ) z
# where count >= 3

with a as(
select *
,lag(people,1) over (order by visit_date) as L1
,lag(people,2) over (order by visit_date) as L2
,lead(people,1) over (order by visit_date) as A1
,lead(people,2) over (order by visit_date) as A2
from stadium
)
select id,visit_date,people from a
where (people>=100 and L1>=100 and L2>=100)
or (people>=100 and a1>=100 and a2>=100)
or (people>=100 and a1>=100 and L1>=100)

