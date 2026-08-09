# Write your MySQL query statement below
Select user_id, concat(
    left(upper(name),1),
    right(lower(name), length(name)-1))
    as name from Users
    Order BY user_id