--
-- @lc app=leetcode id=184 lang=mysql
--
-- [184] Department Highest Salary
--

-- @lc code=start
# Write your MySQL query statement below
select c.Name Department, a.Name Employee, a.Salary from Employee a 
inner join ( select DepartmentId, max(Salary) max_salary from Employee group by DepartmentId) b
on a.DepartmentId=b.DepartmentId
inner join Department c
on a.DepartmentId=c.id
where a.Salary>=b.max_salary;

-- @lc code=end

