select id from (select *, lag(temperature) over(order by recordDate) as lagged,
 lag(recordDate) over(order by recordDate) as pdate
from Weather) t
where temperature > lagged and lagged is not null and datediff(recordDate,pdate)=1
