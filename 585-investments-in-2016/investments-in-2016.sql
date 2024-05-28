# Write your MySQL query statement below
with ans as (select *,
dense_rank() over( order by tiv_2015 ) as dr,
count(tiv_2015) over( partition by tiv_2015 order by tiv_2015 ) as c,
count(concat(lat,lon)) over( partition by lat,lon order by lat,lon ) as ll
from Insurance)

select round(sum(tiv_2016),2) as tiv_2016 from ans 
where c>1 and ll=1
