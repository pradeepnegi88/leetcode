select s.id,a.student from (select *, 
case 
when id%2 = 1 and (count(*) over(order by id
range between unbounded preceding and unbounded following )) = id then id
when id%2 = 1 then id+1
else id-1
end as odd
from Seat)a,Seat s
where a.odd = s.id


