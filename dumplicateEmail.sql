/*

182. Duplicate Emails
Easy

460

25

Add to List

Share
SQL Schema
Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Note: All emails are in lowercase.
*/

# Write your MySQL query statement below

# Group by will have internal count on each record
# then apply condition on that to get only count > 1
# in the problem statement, it was asked to get only duplicate emails or other words eliminate unique ids
# When GROUP BY clause used then to specify conditions on them we should use HAVING clause, WHERE will not work in this case

SELECT Email from Person
GROUP BY Email
HAVING count(Email) > 1;



#SELECT DISTINCT a.Email from Person a, Person b
#WHERE a.Email = b.Email and a.id != b.id;
