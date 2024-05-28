# Write your MySQL query statement below
with cte as (select *,
lag(student,1) over( ) la,
lag(id,1) over( ) lai,

lead(student,1) over( ) le,
lead(id,1) over( ) lei
from Seat
)

select id, coalesce(case when id%2 != 0 then le else la end,student) as  student from cte