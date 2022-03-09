--
-- @lc app=leetcode id=180 lang=mysql
--
-- [180] Consecutive Numbers
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    DISTINCT l1.num ConsecutiveNums
FROM
    LOGS l1,
    LOGS l2,
    LOGS l3
WHERE
    l1.id = l2.id -1
    AND l2.id = l3.id -1
    AND l1.num = l2.num
    AND l2.num = l3.num;

-- @lc code=end