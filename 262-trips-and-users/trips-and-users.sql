# select * from (select distinct(request_at) as Day,round(sum(banned_cancel) OVER( PARTITION BY request_at )/NULLIF(sum(unbanned_users) OVER( PARTITION BY request_at ),2),0)  `Cancellation Rate` from (select *, if (cancel = 1 and banned = 0,1,0) banned_cancel, if (banned= 0,1,0) unbanned_users from  (select customer.id,driver_ban,Customer_ban,status,request_at, if(Customer_ban='No' ,0,1 )  banned, if(status = 'cancelled_by_driver' or status = 'cancelled_by_client',1,0 ) cancel
# from 
# (select u.banned as Customer_ban ,t.status, t.request_at,id
# from users u, trips t
# where client_id = users_id and  request_at between '2013-10-01' and '2013-10-03'
# ) customer
# inner join (select u.banned as driver_ban, id
# from users u, trips t
# where driver_id = users_id and  request_at between '2013-10-01' and '2013-10-03'
# ) driver
# on customer.id = driver.id
# order by request_at) full_table) final) tt
# where  tt.`Cancellation Rate` IS NOT NULL 




select * from (select distinct(request_at) as Day,round(sum(banned_cancel) OVER( PARTITION BY request_at )/nullif(sum(unbanned_users) OVER( PARTITION BY request_at ),0),2)  `Cancellation Rate` from (select *, if (cancel = 1 and banned = 0,1,0) banned_cancel, if (banned= 0,1,0) unbanned_users from  (select customer.id,driver_ban,Customer_ban,status,request_at, if(Customer_ban='No' and driver_ban='No' ,0,1 )  banned, if(status = 'cancelled_by_driver' or status = 'cancelled_by_client',1,0 ) cancel
from 
(select u.banned as Customer_ban ,t.status, t.request_at,id
from users u, trips t
where client_id = users_id and  request_at between '2013-10-01' and '2013-10-03' ) customer
inner join (select u.banned as driver_ban, id
from users u, trips t
where driver_id = users_id and  request_at between '2013-10-01' and '2013-10-03') driver
on customer.id = driver.id
order by request_at) full_table) final) tt
where  tt.`Cancellation Rate` IS NOT NULL 
