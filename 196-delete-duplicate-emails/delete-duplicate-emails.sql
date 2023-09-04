# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete from person where id not in (SELECT id
FROM(Select min(id) as id, Email
from Person
group by Email
) as t)