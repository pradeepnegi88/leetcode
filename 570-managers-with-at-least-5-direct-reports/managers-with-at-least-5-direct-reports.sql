# Write your MySQL query statement below
with managers as (select managerId, count(*)
from Employee
group by managerId
having count(*) >=5)
select name from Employee where exists (select managerId from managers where Employee.id = managers.managerId )