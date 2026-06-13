# Write your MySQL query statement below
select p1.product_name , s1.year, s1.price from sales s1
join Product p1
on s1.product_id = p1.product_id ;
