--
-- @lc app=leetcode id=182 lang=mysql
--
-- [182] Duplicate Emails
--

-- @lc code=start
# Write your MySQL query statement below
select distinct a.Email from Person a inner join (select distinct Id, Email from Person) b on
a.Email=b.Email
where a.Id!=b.Id;
-- select distinct a.Email from Person a, Person b 
-- where a.Id!=b.Id and a.Email=b.Email;
-- @lc code=end

