--
-- @lc app=leetcode id=180 lang=mysql
--
-- [180] Consecutive Numbers
--

-- @lc code=start
# Write your MySQL query statement below
select distinct l1.num ConsecutiveNums from Logs l1, Logs l2, Logs l3
where l1.id=l2.id-1 and l2.id=l3.id-1 
and l1.num=l2.num and l2.num=l3.num;
-- @lc code=end

