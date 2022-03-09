--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--

-- @lc code=start
# Write your MySQL query statement below
select distinct a.id from Weather a join Weather b on
a.RecordDate=date_add(b.RecordDate, interval 1 day)
where 
a.Temperature>b.Temperature;
-- @lc code=end

