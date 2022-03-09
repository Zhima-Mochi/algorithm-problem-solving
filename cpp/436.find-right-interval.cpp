/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<long> search_map;
        int len = intervals.size();
        search_map.reserve(len);
        for (int i = 0; i != len; ++i)
        {
            search_map.push_back(intervals[i][0] * len + i);
        }
        sort(search_map.begin(), search_map.end());
        vector<int> res;
        res.reserve(len);
        for (auto &v : intervals)
        {
            auto iter = lower_bound(search_map.begin(), search_map.end(), v[1] * len);
            if (iter != search_map.end())
            {
                res.push_back((*iter % len + len) % len);
            }
            else
            {
                res.push_back(-1);
            }
        }
        return res;
    }
};
// @lc code=end
