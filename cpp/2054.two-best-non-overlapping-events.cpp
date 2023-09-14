/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 */
#include <vector>
#include <queue>
#include <map>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(n)
class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        map<int, int> gt;
        sort(events.begin(), events.end(), [&](vector<int> &a, vector<int> &b)
             { return a[0] > b[0]; });
        int cur_max = 0;
        for (auto &event : events)
        {
            cur_max = max(cur_max, event[2]);
            gt[event[0] - 1] = max(gt[event[0] - 1], cur_max);
        }
        int res = 0;
        for (auto &event : events)
        {
            res = max(res, event[2] + gt.lower_bound(event[1])->second);
        }
        return res;
    }
};
// @lc code=end
