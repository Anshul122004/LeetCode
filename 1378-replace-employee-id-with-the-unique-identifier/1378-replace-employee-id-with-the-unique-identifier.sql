# Write your MySQL query statement below
Select uni.unique_id, e.name from Employees e
left join EmployeeUNI uni on e.id=uni.id;