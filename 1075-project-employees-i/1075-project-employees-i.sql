# Write your MySQL query statement below
Select p.project_id, ROUND(SUM(e.experience_years)/count(p.employee_id),2) as average_years
from Project p LEFT JOIN Employee e
on p.employee_id=e.employee_id
GROUP BY p.project_id