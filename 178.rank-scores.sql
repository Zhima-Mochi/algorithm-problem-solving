--
-- @lc app=leetcode id=178 lang=mysql
--
-- [178] Rank Scores
--

-- @lc code=start
# Write your MySQL query statement below
select l.Score , _rank 'Rank'  from Scores l left join  (select Score  ,@rank:=@rank+1 _rank from (select Score from Scores group by Score   order by Score desc) l, (select @rank :=0 ) r   ) r 
on l.Score=r.Score order by l.Score desc;
-- SELECT Score, DENSE_RANK() OVER(ORDER BY Score DESC) AS 'Rank' 
-- FROM Scores
-- ORDER BY 'Rank'
-- @lc code=end

