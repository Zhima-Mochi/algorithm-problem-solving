/*
 * @lc app=leetcode id=2532 lang=cpp
 *
 * [2532] Time to Cross a Bridge
 */
#include <vector>
#include <queue>
#include <map>
#include <climits>
using namespace std;
// @lc code=start
// t:O(nlog(k)), s:O(k)
class Solution
{
public:
    int findCrossingTime(int n, int k, vector<vector<int>> &time)
    {
        auto comp = [&](int i, int j)
        {
            return time[i][0] + time[i][2] < time[j][0] + time[j][2] || time[i][0] + time[i][2] == time[j][0] + time[j][2] && i < j;
        };
        priority_queue<int, vector<int>, decltype(comp)> pq_left(comp), pq_right(comp);
        int t = 0;
        map<int, vector<int>> timeline_left, timeline_right;
        for (int i = 0; i != k; ++i)
        {
            pq_left.push(i);
        }
        while (n || !timeline_right.empty() || !pq_right.empty())
        {
            while (!timeline_left.empty() && timeline_left.begin()->first <= t)
            {
                for (auto idx : timeline_left.begin()->second)
                {
                    pq_left.push(idx);
                }
                timeline_left.erase(timeline_left.begin());
            }
            while (!timeline_right.empty() && timeline_right.begin()->first <= t)
            {
                for (auto idx : timeline_right.begin()->second)
                {
                    pq_right.push(idx);
                }
                timeline_right.erase(timeline_right.begin());
            }

            if (!pq_right.empty())
            {
                int worker = pq_right.top();
                pq_right.pop();
                if (n > 0)
                {
                    timeline_left[t + time[worker][2] + time[worker][3]].push_back(worker);
                }
                t += time[worker][2];
            }
            else if (n > 0 && !pq_left.empty())
            {
                int worker = pq_left.top();
                pq_left.pop();
                timeline_right[t + time[worker][0] + time[worker][1]].push_back(worker);
                t += time[worker][0];
                if (n > 0)
                {
                    --n;
                }
            }
            else
            {
                int next_t = INT_MAX;
                if (!timeline_left.empty())
                {
                    next_t = min(timeline_left.begin()->first, next_t);
                }
                if (!timeline_right.empty())
                {
                    next_t = min(timeline_right.begin()->first, next_t);
                }
                if (next_t != INT_MAX)
                {
                    t = max(t, next_t);
                }
            }
        }
        return t;
    }
};
// @lc code=end;