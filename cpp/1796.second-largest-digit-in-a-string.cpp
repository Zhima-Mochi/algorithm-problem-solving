/*
 * @lc app=leetcode id=1796 lang=cpp
 *
 * [1796] Second Largest Digit in a String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int secondHighest(string s)
    {
        bool dg_exist[10] = {};
        for (auto c : s)
        {
            if (isdigit(c))
            {
                dg_exist[c - '0'] = true;
            }
        }
        int exist_cnt = 0;
        for (int i = 9; i != -1; --i)
        {
            if (dg_exist[i])
            {
                ++exist_cnt;
            }
            if (exist_cnt == 2)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
