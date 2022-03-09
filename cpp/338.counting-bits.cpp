/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res = {0};
        for (int i = 1; i <= n; ++i)
        {
            res.push_back(res[(i - 1) & i] + 1);
        }
        return res;
        // vector<int> res={0};
        // while (n)
        // {
        //     int len = min(n, static_cast<int>(res.size()));
        //     for (int j = 0; j < len; ++j)
        //     {
        //         res.push_back(res[j] + 1);
        //     }
        //     n -= len;
        // }
        // return res;
    }
};
// @lc code=end
