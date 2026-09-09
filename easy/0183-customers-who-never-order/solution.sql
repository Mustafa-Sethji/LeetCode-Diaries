# Write your MySQL query statement below
select email Email
FROM Person 
GROUP BY email
HAVING COUNT(DISTINCT id)>1