/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int index = -1;
        int accum = 0;
        int count = 0;
        int len = gas.size();
        for (int i = 0; i != len; ++i)
        {
            auto profit = gas[i] - cost[i];
            accum += profit;
            if (index == -1 && profit >= 0)
            {
                index = i;
                count = profit;
            }
            else if (index != -1 && (count += profit) < 0)
            {
                index = -1;
            }
        }
        return accum >= 0 ? index : -1;
    }
};
// @lc code=end
