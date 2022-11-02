# Write your MySQL query statement below
Select user_id, CONCAT(Upper(Substr(name, 1, 1)), Lower(Substr(name, 2, length(name)))) as name
From users order by user_id;