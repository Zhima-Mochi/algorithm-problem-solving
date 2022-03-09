--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    a.Name AS Employee
FROM
    Employee a
    INNER JOIN Employee b ON a.ManagerId = b.Id
WHERE
    a.Salary > b.Salary;

-- @lc code=end