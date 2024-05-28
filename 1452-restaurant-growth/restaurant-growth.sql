with g as (
    select customer_id,name, visited_on, sum(amount) as amount from Customer group by visited_on
    )

,

 f as ( select *,
       sum(amount) over (order by visited_on rows between 6 preceding and current row ) s,
       ROUND(AVG(amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) AS a
from g)

select visited_on,s as amount ,a as average_amount
from f
where visited_on >= (select min(visited_on) as visited_on from f )+6
order by visited_on
