--
-- @lc app=leetcode id=620 lang=mysql
--
-- [620] Not Boring Movies
--

-- @lc code=start
# Write your MySQL query statement below
select * from Cinema 
where description !='boring' and id%2
order by rating desc; 
-- @lc code=end

