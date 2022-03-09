--
-- @lc app=leetcode id=196 lang=mysql
--
-- [196] Delete Duplicate Emails
--
-- @lc code=start
# Write your MySQL query statement below
DELETE a
FROM
    Person AS a
    LEFT JOIN (
        SELECT
            min(Id) Id,
            Email
        FROM
            Person
        GROUP BY
            Email
    ) AS b ON a.Email = b.Email
WHERE
    a.Id > b.Id;

-- @lc code=end