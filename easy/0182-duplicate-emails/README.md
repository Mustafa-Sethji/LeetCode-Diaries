# Duplicate Emails

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.


 

Write a solution to report all the duplicate emails. Note that it's guaranteed that the email field is not NULL.

Return the result table in any order.

The result format is in the following example.

 
Example 1:

Input: 
Person table:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
Output: 
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Explanation: a@b.com is repeated two times.

## Solution

**Language:** SQL  
**Runtime:** 83 ms  
**Memory:** 0B  
**Submitted:** 2026-09-09T17:00:42.355Z  

```sql
# Write your MySQL query statement below
SELECT e1.name Employee
FROM Employee e1
INNER JOIN Employee e2
ON e1.managerId=e2.id
WHERE e1.salary>e2.salary
```

---

[View on LeetCode](https://leetcode.com/problems/duplicate-emails/)