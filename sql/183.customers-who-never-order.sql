--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    Name Customers
FROM
    Customers a
    LEFT JOIN Orders b ON a.Id = b.CustomerId
WHERE
    b.CustomerId IS NULL;

-- @lc code=end