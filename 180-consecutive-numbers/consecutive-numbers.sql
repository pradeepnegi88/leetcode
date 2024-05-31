select distinct t1.num as consecutivenums
from logs t1
join logs t2 on t1.id + 1 = t2.id
join logs t3 on t1.id + 2 = t3.id
where t1.num = t2.num and t2.num = t3.num;
