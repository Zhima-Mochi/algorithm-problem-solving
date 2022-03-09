/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int cnt = 0;
        char prev = '0';
        for (auto c : s)
        {
            if (prev == '0' && c == '1')
            {
                ++cnt;
                if (cnt == 2)
                {
                    return false;
                }
            }
            prev = c;
        }
        return cnt == 1;
    }
};
// @lc code=end
