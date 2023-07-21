/*
 * @lc app=leetcode id=1499 lang=cpp
 *
 * [1499] Max Value of Equation
 */
#include <vector>
#include <deque>
#include <climits>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        deque<pair<int, int>> dq;
        int w = points.size();
        int res = INT_MIN;
        for (int i = 0; i != w; ++i)
        {
            int x = points[i][0];
            int y = points[i][1];
            while (!dq.empty() && x - dq.front().second > k)
            {
                dq.pop_front();
            }
            if (!dq.empty())
            {
                res = max(res, x + y + dq.front().first);
            }
            while (!dq.empty() && dq.back().first <= y - x)
            {
                dq.pop_back();
            }
            dq.push_back({y - x, x});
        }
        return res;
    }
};
// @lc code=end
