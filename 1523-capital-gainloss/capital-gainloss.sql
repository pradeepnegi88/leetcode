# Write your MySQL query statement below
with temp as (select *, dense_rank() over(partition by operation,stock_name order by operation_day ) ds
from stocks)

select seller.stock_name,sum(seller.price - buyer.price) as capital_gain_loss from(select * from temp where operation = "Sell")
seller
inner join (select * from temp where operation = "Buy" ) buyer
on seller.stock_name = buyer.stock_name and  seller.ds = buyer.ds
group by seller.stock_name

