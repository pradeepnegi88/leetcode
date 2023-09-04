# Write your MySQL query statement below
with t as ( select count(order_number) as c,customer_number
from Orders
group by customer_number
order by c desc
limit 1
)

select customer_number 
from t

