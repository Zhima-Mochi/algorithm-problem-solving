/*
 * @lc app=leetcode id=1422 lang=java
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
    public int maxScore(String s) {
        int one_count = 0;
        int width = s.length();
        for (int i = 1; i != width; ++i)
        {
            if (s.charAt(i) == '1')
            {
                ++one_count;
            }
        }
        int score = (s.charAt(0) == '0' ? 1 : 0) + one_count;
        int res = score;

        for (int i = 1; i < width - 1; ++i)
        {
            if (s.charAt(i) == '1')
            {
                --score;
            }
            else
            {
                ++score;
                res = Math.max(res, score);
            }
        }
        return res;
    }
}
// @lc code=end

