--
-- @lc app=leetcode id=182 lang=mysql
--
-- [182] Duplicate Emails
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    DISTINCT a.Email
FROM
    Person a
    INNER JOIN (
        SELECT
            DISTINCT Id,
            Email
        FROM
            Person
    ) b ON a.Email = b.Email
WHERE
    a.Id != b.Id;

-- select distinct a.Email from Person a, Person b 
-- where a.Id!=b.Id and a.Email=b.Email;
-- @lc code=end