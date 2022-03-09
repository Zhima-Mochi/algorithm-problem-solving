/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &p1, const vector<int> &p2)
             { return p1[0] < p2[0]; });
        int left = intervals[0][0], right = intervals[0][1];
        for (auto & pair : intervals)
        {
            if (pair[0] > right)
            {
                res.push_back(vector<int>{left, right});
                left = pair[0];
                right = pair[1];
            }
            else
            {
                right = max(right, pair[1]);
            }
        }
        res.push_back(vector<int>{left, right});
        return res;
    }
};
// @lc code=end
