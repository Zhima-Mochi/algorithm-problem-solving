--
-- @lc app=leetcode id=620 lang=mysql
--
-- [620] Not Boring Movies
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    *
FROM
    Cinema
WHERE
    description != 'boring'
    AND id % 2
ORDER BY
    rating DESC;

-- @lc code=end