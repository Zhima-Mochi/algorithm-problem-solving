/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        for (auto &pair : ops)
        {
            m = min(m, pair[0]);
            n = min(n, pair[1]);
        }
        return m * n;
    }
};
// @lc code=end
