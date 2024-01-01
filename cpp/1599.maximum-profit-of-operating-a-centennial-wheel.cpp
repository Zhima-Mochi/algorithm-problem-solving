/*
 * @lc app=leetcode id=1599 lang=cpp
 *
 * [1599] Maximum Profit of Operating a Centennial Wheel
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
    {
        int ans = -1;
        if (4 * boardingCost <= runningCost)
        {
            return ans;
        }
        int rest = 0;
        int net = 0;
        int mx_net = 0;
        int times = 0;
        for (auto customer : customers)
        {
            times++;
            rest += customer;
            if (rest >= 4)
            {
                net += 4 * boardingCost;
                rest -= 4;
            }
            else
            {
                net += rest * boardingCost;
                rest = 0;
            }
            net -= runningCost;
            if (net > mx_net)
            {
                mx_net = net;
                ans = times;
            }
        }
        if (net + (rest / 4 * 4) * boardingCost - runningCost * (rest / 4) > mx_net)
        {
            mx_net = net + (rest / 4 * 4) * boardingCost - runningCost * (rest / 4);
            ans = times + rest / 4;
        }
        if (net + rest * boardingCost - runningCost * (rest / 4 + 1) > mx_net)
        {
            ans = times + rest / 4 + 1;
        }
        return ans;
    }
};
// @lc code=end
