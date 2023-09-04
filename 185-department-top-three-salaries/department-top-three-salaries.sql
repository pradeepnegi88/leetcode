select d.name as Department , e.name as Employee , salary as Salary
from (select *,dense_rank() OVER (PARTITION BY departmentId ORDER BY salary DESC) roe
from Employee ) e, Department d
where e.departmentId = d.id and 
e.roe <=3


