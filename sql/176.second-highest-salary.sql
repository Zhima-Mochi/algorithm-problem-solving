--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    max(Salary) AS SecondHighestSalary
FROM
    Employee
WHERE
    Salary < (
        SELECT
            max(Salary)
        FROM
            Employee
    );

-- @lc code=end