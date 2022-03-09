/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxScore(string s)
    {
        int one_count = 0;
        int width = s.size();
        for (int i = 1; i != width; ++i)
        {
            if (s[i] == '1')
            {
                ++one_count;
            }
        }
        int score = (s[0] == '0' ? 1 : 0) + one_count;
        int res = score;

        for (int i = 1; i < width - 1; ++i)
        {
            if (s[i] == '1')
            {
                --score;
            }
            else
            {
                ++score;
                res = max(res, score);
            }
        }
        return res;
    }
};
// @lc code=end
