--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--

-- @lc code=start
# Write your MySQL query statement below
select Name Customers from Customers a left join Orders b
on a.Id=b.CustomerId
where b.CustomerId is null;
-- @lc code=end

