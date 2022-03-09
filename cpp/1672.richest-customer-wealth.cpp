/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int res = 0;
        for (auto &acc : accounts)
        {
            int wealth = accumulate(acc.begin(), acc.end(), 0);
            res = max(res, wealth);
        }
        return res;
    }
};
// @lc code=end
