with a as (
    select 
        mr.*, 
        m.title, 
        u.name, 
        count(*) over(partition by u.name order by u.name) as ct,
        avg(case when extract(year from mr.created_at) = 2020 and extract(month from mr.created_at) = 2 then mr.rating end)over(partition by m.title)  as ag,
        extract(month from mr.created_at) as mon 
    from Movies m
    join MovieRating mr on m.movie_id = mr.movie_id
    join Users u on u.user_id = mr.user_id
)

(select distinct(name) as results 
 from a 
 where ct = (select max(ct) from a)
 order by name 
 limit 1)
union all 
(select distinct(title) as results 
 from a 
 where mon = 2 and ag = (select max(ag) from a where mon = 2)
 order by title 
 limit 1);


-- select  * from a where mon = 2