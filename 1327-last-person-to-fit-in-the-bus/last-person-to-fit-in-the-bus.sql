with q as (select *, sum(weight) over(order by turn) as s
from Queue)

select person_name from q where s<=1000
order by turn desc
limit 1