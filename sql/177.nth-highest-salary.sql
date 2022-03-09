--
-- @lc app=leetcode id=177 lang=mysql
--
-- [177] Nth Highest Salary
--
-- @lc code=start
# Write your MySQL query statement below.
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN declare pos INT DEFAULT N -1;

RETURN (
  SELECT
    DISTINCT Salary
  FROM
    Employee
  ORDER BY
    Salary DESC
  LIMIT
    1 OFFSET pos
);

END -- @lc code=end