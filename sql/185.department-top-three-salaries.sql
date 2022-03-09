--
-- @lc app=leetcode id=185 lang=mysql
--
-- [185] Department Top Three Salaries
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    a.Department,
    a.Name Employee,
    a.Salary
FROM
    (
        SELECT
            a.Id,
            a.Name,
            a.Salary,
            a.DepartmentId,
            b.Name Department
        FROM
            Employee a
            JOIN Department b ON a.DepartmentId = b.Id
    ) a
    INNER JOIN (
        SELECT
            RANK() over (
                PARTITION by a.DepartmentId
                ORDER BY
                    a.Salary DESC
            ) salary_rank,
            a.DepartmentId,
            a.Salary
        FROM
            (
                SELECT
                    DISTINCT DepartmentId,
                    Salary
                FROM
                    Employee
            ) a
    ) b ON a.DepartmentId = b.DepartmentId
    AND a.Salary = b.Salary
WHERE
    b.salary_rank <= 3;

-- @lc code=end