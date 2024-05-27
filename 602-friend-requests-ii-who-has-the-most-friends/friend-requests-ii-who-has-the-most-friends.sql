with t as (
    select 
        requester_id,
        accepter_id,
        accept_date,
        count(requester_id) over (partition by requester_id order by requester_id) as cr,
        count(accepter_id) over (partition by accepter_id order by accepter_id) as ca
    from requestaccepted
),
combined as (
    select requester_id as id, cr as num
    from t
    group by id
    union all
    select accepter_id as id, ca as num
    from t
    group by id
),
aggregated as (
    select id, sum(num) as num
    from combined
    group by id
),
max_num as (
    select max(num) as max_num
    from aggregated
)
select *
from aggregated
where num = (select max_num from max_num);
