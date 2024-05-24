# Write your MySQL query statement below
with s as (select product_id, year ,quantity,price, dense_rank() over( partition by product_id order by year ) as dr
from Sales
)
select product_id,year as first_year,quantity,price from s where dr =1

