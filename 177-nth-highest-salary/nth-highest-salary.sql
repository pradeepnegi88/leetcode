CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE lvl_counter INT;
SET lvl_counter = N-1;
  RETURN (
     select distinct(salary) 
     from Employee
     order by salary desc
     limit 1 offset lvl_counter
  );
END