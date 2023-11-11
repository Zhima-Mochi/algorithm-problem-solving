/*
 * @lc app=leetcode id=2609 lang=cpp
 *
 * [2609] Find the Longest Balanced Substring of a Binary String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int prev_zero = 0;
        int cnt_one = 0;
        int res = 0;
        for (auto c : s)
        {
            if (c == '0')
            {
                if (cnt_one)
                {
                    cnt_one = 0;
                    prev_zero = 0;
                }
                prev_zero++;
            }
            else
            {
                cnt_one++;
            }
            res = max(res, 2 * min(cnt_one, prev_zero));
        }
        return res;
    }
};
// @lc code=end
