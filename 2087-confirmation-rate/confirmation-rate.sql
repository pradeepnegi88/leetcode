# Write your MySQL query statement below
 
select s.user_id,coalesce(ROUND(confirmation_rate,2),0.00) as confirmation_rate
from  Signups as s
left join(select user_id, sum(case when action = "confirmed" then 1 else 0 end) /count(*) as confirmation_rate
from Confirmations
group by user_id) as g
on s.user_id = g.user_id
