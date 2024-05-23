# Write your MySQL query statement below

with ans as (select d.name as Department,e.name as Employee,e.salary as Salary,
dense_rank() over(partition by departmentId order by salary desc) as dr
from Employee e
join Department d
on e.departmentId = d.id)

select Department, Employee, Salary from ans where dr <4