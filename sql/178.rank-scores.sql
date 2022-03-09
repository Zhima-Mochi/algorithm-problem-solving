--
-- @lc app=leetcode id=178 lang=mysql
--
-- [178] Rank Scores
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    l.Score,
    _rank 'Rank'
FROM
    Scores l
    LEFT JOIN (
        SELECT
            Score,
            @rank := @rank + 1 _rank
        FROM
            (
                SELECT
                    Score
                FROM
                    Scores
                GROUP BY
                    Score
                ORDER BY
                    Score DESC
            ) l,
            (
                SELECT
                    @rank := 0
            ) r
    ) r ON l.Score = r.Score
ORDER BY
    l.Score DESC;

-- SELECT Score, DENSE_RANK() OVER(ORDER BY Score DESC) AS 'Rank' 
-- FROM Scores
-- ORDER BY 'Rank'
-- @lc code=end