--
-- @lc app=leetcode id=185 lang=mysql
--
-- [185] Department Top Three Salaries
--

-- @lc code=start
# Write your MySQL query statement below
select  a.Department,a.Name Employee, a.Salary  from 
(select a.Id, a.Name, a.Salary, a.DepartmentId ,b.Name Department from Employee a join Department b
on a.DepartmentId=b.Id ) a  
inner join 
(select RANK() over (partition by a.DepartmentId order by a.Salary desc) salary_rank ,a.DepartmentId,a.Salary from (select distinct DepartmentId,Salary from Employee) a )b
on a.DepartmentId=b.DepartmentId and a.Salary=b.Salary
where b.salary_rank<=3;
-- @lc code=end

