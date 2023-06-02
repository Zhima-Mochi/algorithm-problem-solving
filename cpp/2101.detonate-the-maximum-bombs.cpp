/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
// t:O(n^3), s:O(n^2)
class Solution
{
    int can_reach(vector<int> &l, vector<int> &r)
    {
        long long x = l[0] - r[0];
        long long y = l[1] - r[1];
        long long d = l[2];
        return x * x + y * y <= d * d;
    };

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int w = bombs.size();
        vector<vector<int>> edges(w);
        for (int i = 0; i != w; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                if (can_reach(bombs[i], bombs[j]))
                {
                    edges[i].push_back(j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            queue<int> q;
            q.push(i);
            vector<bool> visited(w);
            visited[i] = true;
            int count = 0;
            while (!q.empty())
            {
                int b = q.front();
                q.pop();
                count++;
                for (auto next : edges[b])
                {
                    if (!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            res = max(res, count);
        }
        return res;
    }
};
// @lc code=end
