/*
 * @lc app=leetcode id=517 lang=cpp
 *
 * [517] Super Washing Machines
 */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMinMoves(vector<int> &machines)
    {
        int sum_val = accumulate(machines.begin(), machines.end(), 0);
        int width = machines.size();
        if (sum_val % width)
        {
            return -1;
        }
        int required_val = sum_val / width;
        int res = 0;
        int left_sum = 0;
        for (int i = 0; i != width; ++i)
        {
            int pressure = left_sum - i * required_val;
            left_sum += machines[i];
            if (pressure < 0)
            {
                //pass to left : -pressure
                //pass to right : max(machines[i] + pressure - required_val, 0)
                res = max(res, -pressure + max(machines[i] + pressure - required_val, 0));
            }
            else
            {
                //pass to right and receive : pressure
                res = max(res, pressure);
            }
        }
        return res;
    }
};
// @lc code=end