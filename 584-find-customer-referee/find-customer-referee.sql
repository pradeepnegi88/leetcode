# Write your MySQL query statement below
select name from 
Customer 
where (id,name) not in (
select id,name 
from Customer 
where referee_id = 2
)


