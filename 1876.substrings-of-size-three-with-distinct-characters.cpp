/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int width = s.size();
        if (width < 3)
        {
            return 0;
        }
        string count(26, 0);
        int repeat = 0;
        for (int i = 0; i != 3; ++i)
        {
            if (++count[s[i] - 'a'] == 2)
            {
                ++repeat;
            }
        }
        int res = repeat == 0 ? 1 : 0;
        for (int i = 3; i != width; ++i)
        {
            if (++count[s[i] - 'a'] == 2)
            {
                ++repeat;
            }
            if (--count[s[i - 3] - 'a'] == 1)
            {
                --repeat;
            }
            if (repeat == 0)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
