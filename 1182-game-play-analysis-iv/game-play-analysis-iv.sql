with c as (
  select player_id,
    DATEDIFF(lead(event_date) over (partition by player_id order by event_date) , event_date) as l,
    row_number() over (partition by player_id order by event_date) as r
  from activity
)



select round((
  select count(*) 
  from c
  where l = 1 and  r = 1
) / (
  select count(distinct player_id) 
  from activity
),2 )as fraction;

