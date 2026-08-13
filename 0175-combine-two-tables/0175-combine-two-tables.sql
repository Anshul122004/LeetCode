# Write your MySQL query statement below
Select p.firstName as firstName, p.lastName as lastName, a.city as city, a.state as state
from Person p
Left JOIN Address a
on p.personId=a.personId