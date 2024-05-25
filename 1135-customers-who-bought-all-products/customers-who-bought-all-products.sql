with a as 
(select c.customer_id,count(distinct(c.product_key)) as ct
from Customer as c
group by customer_id)

select customer_id from a where a.ct = (select count(*) from Product)


