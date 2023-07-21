/*
 * @lc app=leetcode id=1943 lang=cpp
 *
 * [1943] Describe the Painting
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(log(n))
class Solution
{
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        sort(segments.begin(), segments.end(), [&](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<long long>> res;
        int prev_pos = segments[0][0];
        long long color = 0;
        int w = segments.size();
        for (int i = 0; i != w; ++i)
        {
            while (!pq.empty() && segments[i][0] > pq.top().first)
            {
                if (prev_pos != pq.top().first)
                {
                    res.push_back({prev_pos, pq.top().first, color});
                }
                color -= pq.top().second;
                prev_pos = pq.top().first;
                pq.pop();
            }
            if (prev_pos != segments[i][0] && color > 0)
            {
                res.push_back({prev_pos, segments[i][0], color});
            }
            pq.push({segments[i][1], segments[i][2]});
            color += segments[i][2];
            prev_pos = segments[i][0];
        }
        while (!pq.empty())
        {
            if (prev_pos != pq.top().first)
            {
                res.push_back({prev_pos, pq.top().first, color});
            }
            color -= pq.top().second;
            prev_pos = pq.top().first;
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
