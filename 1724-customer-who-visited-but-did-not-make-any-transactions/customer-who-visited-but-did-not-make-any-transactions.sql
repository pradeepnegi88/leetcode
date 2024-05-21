# Write your MySQL query statement below
with f as (select 
v.customer_id,t.transaction_id
from Visits v
left join Transactions t
on v.visit_id = t.visit_id
where t.transaction_id is null
)
select customer_id, count(*) as count_no_trans from f group by customer_id
