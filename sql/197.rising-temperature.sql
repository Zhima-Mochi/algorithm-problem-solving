--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    DISTINCT a.id
FROM
    Weather a
    JOIN Weather b ON a.RecordDate = date_add(b.RecordDate, INTERVAL 1 DAY)
WHERE
    a.Temperature > b.Temperature;

-- @lc code=end