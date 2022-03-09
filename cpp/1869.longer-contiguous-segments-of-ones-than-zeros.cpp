/*
 * @lc app=leetcode id=1869 lang=cpp
 *
 * [1869] Longer Contiguous Segments of Ones than Zeros
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        int cum = 1;
        int one_max = 0, zero_max = 0;
        for (int i = 1, width = s.size(); i != width; ++i)
        {
            if (s[i] == s[i - 1])
            {
                ++cum;
            }
            else
            {
                if (s[i] == '1')
                {
                    zero_max = max(zero_max, cum);
                }
                else
                {
                    one_max = max(one_max, cum);
                }
                cum = 1;
            }
        }
        if (s.back() == '1')
        {
            one_max = max(one_max, cum);
        }
        else
        {
            zero_max = max(zero_max, cum);
        }
        return one_max > zero_max;
    }
};
// @lc code=end
