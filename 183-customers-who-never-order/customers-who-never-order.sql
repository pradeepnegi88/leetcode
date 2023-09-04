select name as Customers from Customers 
where (name,id) not in (select c.name as Customers,c.id
from Customers c,Orders o
where o.customerId = c.id)
