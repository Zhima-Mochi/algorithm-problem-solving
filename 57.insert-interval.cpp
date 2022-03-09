/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        bool is_in_res = false;
        if (intervals.size() == 0)
        {
            res.push_back(newInterval);
            return res;
        }
        int i = 0, len = intervals.size();
        for (; i != len; i++)
        {

            if (intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                break;
            }
        }
        res.push_back(newInterval);
        for (; i < len; i++)
        {
            if (intervals[i][0] <= res.back()[1])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                break;
            }
        }
        for (; i < len; i++)
        {
            res.push_back(intervals[i]);
        }
        return res;
    }
};
// @lc code=end
