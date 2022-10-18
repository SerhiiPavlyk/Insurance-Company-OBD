use SUPPORT
select name as "User name", ID_USER as "User ID", ID_ITEM as "Item ID", object_name as "Object name", start_date as "Start date", end_date as "End date", price as "Insurance price", state as "Insurance state", balance as "User's balance"
from registered_objects
inner join userinfo
on ID_USER = userinfo.id
order by id ASC

update registered_objects
set state = 'g'
where ID_ITEM = 2

insert into registered_objects (ID_USER, ID_ITEM, object_name, start_date, end_date ,price, state)
values(102,15,'Iphone','2022-12-17','2022-12-17',100,'j')
select  ID_USER, ID_ITEM, object_name, start_date, end_date ,price, state
from registered_objects

select MAX(ID_ITEM) from registered_objects

delete from registered_objects where state = 'скасовано(під видалення)'

select name as "User name", ID_USER as "User_ID", ID_ITEM as "Item ID", object_name as "Object name",
start_date as "Start date", end_date as "End date", price as "Insurance price",
state as "Insurance state", balance as "User's balance" from registered_objects
inner join userinfo on ID_USER = id 
where ID_USER = 102
order by id ASC 