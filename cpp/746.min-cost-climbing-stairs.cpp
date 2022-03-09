/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int len = cost.size();
        for (int i = 2; i != len; ++i)
        {
            cost[i] += min(cost[i - 2], cost[i - 1]);
        }
        return min(cost[len - 1], cost[len - 2]);
    }
};
// @lc code=end
