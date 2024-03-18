--
-- @lc app=leetcode.cn id=175 lang=mysql
--
-- [175] 组合两个表
--

-- @lc code=start
# Write your MySQL query statement below
SELECT a.firstname, a.lastname, b.city, b.state
FROM Person a
    LEFT JOIN Address b ON a.personId = b.personID;
-- @lc code=end