--
-- @lc app=leetcode id=627 lang=mysql
--
-- [627] Swap Salary
--
-- @lc code=start
# Write your MySQL query statement below
UPDATE
    Salary
SET
    sex = char(11 ^ ascii(sex));

-- update Salary
-- set sex = case when sex='m' then 'f' else 'm' end;
-- @lc code=end