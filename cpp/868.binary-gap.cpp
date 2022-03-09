/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */
#include<algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int binaryGap(int n)
    {
        while (n && n % 2 == 0)
        {
            n /= 2;
        }
        n /= 2;
        int res = 0;
        while (n)
        {
            int accum = 1;
            while (n && n % 2 == 0)
            {
                ++accum;
                n /= 2;
            }
            if (n)
            {
                res = max(res, accum);
                n /= 2;
            }
        }
        return res;
    }
};
// @lc code=end
