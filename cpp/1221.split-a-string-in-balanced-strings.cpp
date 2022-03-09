/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int R_count = 0;
        int res = 0;
        for (auto c : s)
        {
            if (c == 'R')
            {
                ++R_count;
            }
            else
            {
                --R_count;
            }
            if (R_count == 0)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
