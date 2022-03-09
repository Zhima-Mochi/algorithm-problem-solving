/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
//T: max(O(nlogn), O(mlogn)) S: O(1)
class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (auto h : houses)
        {
            auto right_heater_iter = lower_bound(heaters.begin(), heaters.end(), h);
            auto right_heater = right_heater_iter == heaters.end() ? INT32_MAX : *right_heater_iter;
            if (right_heater - h <= res)
            {
                continue;
            }
            else if (right_heater_iter == heaters.begin())
            {
                res = right_heater - h;
                continue;
            }
            auto left_heater = *prev(right_heater_iter);
            if (h - left_heater <= res)
            {
                continue;
            }
            res = min(h - left_heater, right_heater - h);
        }
        return res;
    }
};
// @lc code=end
