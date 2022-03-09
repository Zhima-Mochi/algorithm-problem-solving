--
-- @lc app=leetcode id=184 lang=mysql
--
-- [184] Department Highest Salary
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    c.Name Department,
    a.Name Employee,
    a.Salary
FROM
    Employee a
    INNER JOIN (
        SELECT
            DepartmentId,
            max(Salary) max_salary
        FROM
            Employee
        GROUP BY
            DepartmentId
    ) b ON a.DepartmentId = b.DepartmentId
    INNER JOIN Department c ON a.DepartmentId = c.id
WHERE
    a.Salary >= b.max_salary;

-- @lc code=end