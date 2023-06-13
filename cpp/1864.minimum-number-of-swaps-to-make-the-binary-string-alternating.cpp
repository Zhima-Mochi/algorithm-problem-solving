/*
 * @lc app=leetcode id=1864 lang=cpp
 *
 * [1864] Minimum Number of Swaps to Make the Binary String Alternating
 */
#include <string>
#include <climits>
using namespace std;
// @lc code=start
// t:O(n) s:O(1)
class Solution
{
public:
    int minSwaps(string s)
    {
        int extra_0 = 0, extra_1 = 0, extra_2 = 0, extra_3 = 0;
        int w = s.size();
        for (int i = 0; i != w; ++i)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '1')
                {
                    ++extra_1;
                }
                else
                {
                    ++extra_2;
                }
            }
            else
            {
                if (s[i] == '0')
                {
                    ++extra_0;
                }
                else
                {
                    ++extra_3;
                }
            }
        }
        if (extra_0 != extra_1 && extra_2 != extra_3)
        {
            return -1;
        }

        int res = INT_MAX;
        if (extra_0 == extra_1)
        {
            res = min(res, extra_0);
        }
        if (extra_2 == extra_3)
        {
            res = min(res, extra_2);
        }

        return res;
    }
};
// @lc code=end
