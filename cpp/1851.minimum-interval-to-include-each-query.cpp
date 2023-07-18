/*
 * @lc app=leetcode id=1851 lang=cpp
 *
 * [1851] Minimum Interval to Include Each Query
 */
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O((n+m)log(n+m)), s:O(n+m)
class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        auto comp = [&](vector<int> &l, vector<int> &r)
        {
            return l[1] - l[0] > r[1] - r[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        unordered_map<int, int> um;
        auto cp = queries;
        sort(cp.begin(), cp.end());
        int cur = 0;
        int w = intervals.size();
        for (auto val : cp)
        {
            while (cur != w && (intervals[cur][0] <= val))
            {
                pq.push({intervals[cur]});
                cur++;
            }
            while (!pq.empty() && pq.top()[1] < val)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                um[val] = pq.top()[1] - pq.top()[0] + 1;
            }
            else
            {
                um[val] = -1;
            }
        }
        vector<int> res;
        for (auto q : queries)
        {
            res.push_back(um[q]);
        }
        return res;
    }
};
// @lc code=end
