 with categories as (
    select 'Low Salary' AS category
    union
    select 'Average Salary' AS category
    union
    select 'High Salary' AS category
),
 a as (select (case 
             when income < 20000 then "Low Salary"   
             when income >=20000 and income <=50000 then "Average Salary"  
             when income >50000 then  "High Salary" end) as cat
  from accounts),

b as (select c.* , a.*   from categories as c left join  a on c.category = a.cat)


 select category, count(cat) as accounts_count from b   group by       category 