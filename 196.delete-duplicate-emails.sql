--
-- @lc app=leetcode id=196 lang=mysql
--
-- [196] Delete Duplicate Emails
--

-- @lc code=start
# Write your MySQL query statement below
delete a from Person as a
left join (select min(Id) Id,Email from Person group by Email) as b on
a.Email=b.Email
where a.Id>b.Id;
-- @lc code=end

