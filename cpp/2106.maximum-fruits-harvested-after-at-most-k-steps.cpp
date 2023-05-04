/*
 * @lc app=leetcode id=2106 lang=cpp
 *
 * [2106] Maximum Fruits Harvested After at Most K Steps
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        fruits.push_back({200001, 0});
        int w = fruits.size();
        int find_first_right = 0;
        int left = 0, right = w;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (fruits[mid][0] < startPos)
            {
                left += 1;
            }
            else
            {
                right = mid;
            }
        }
        find_first_right = left;
        vector<vector<int>> right_cost_profit, left_cost_profit;
        right_cost_profit.push_back({0, 0});
        left_cost_profit.push_back({0, 0});
        for (int i = find_first_right; i != w; ++i)
        {
            if (fruits[i][0] - startPos > k)
            {
                break;
            }
            right_cost_profit.push_back({fruits[i][0] - startPos, fruits[i][1] + right_cost_profit.back()[1]});
        }
        for (int i = find_first_right - 1; i != -1; --i)
        {
            if (startPos - fruits[i][0] > k)
            {
                break;
            }
            left_cost_profit.push_back({startPos - fruits[i][0], fruits[i][1] + left_cost_profit.back()[1]});
        }
        int rw = right_cost_profit.size();
        int lw = left_cost_profit.size();
        int res = 0;
        int pos = 0;
        for (int i = rw - 1; i != -1; --i)
        {
            while (pos + 1 < lw && 2 * left_cost_profit[pos + 1][0] + right_cost_profit[i][0] <= k)
            {
                pos += 1;
            }

            res = max(res, left_cost_profit[pos][1] + right_cost_profit[i][1]);
        }
        pos = 0;
        for (int i = lw - 1; i != -1; --i)
        {
            while (pos + 1 < rw && 2 * right_cost_profit[pos + 1][0] + left_cost_profit[i][0] <= k)
            {
                pos += 1;
            }
            res = max(res, right_cost_profit[pos][1] + left_cost_profit[i][1]);
        }
        return res;
    }
};
// @lc code=end
