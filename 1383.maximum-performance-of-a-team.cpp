/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
    using sp = int;
    using eff = int;

public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<sp,eff>> v1;
        for (int i = 0; i != n; ++i)
        {
            v1.push_back({speed[i], efficiency[i]});
        }
        sort(v1.begin(), v1.end(), [](auto &l, auto &r)
             { return l.first > r.first; });
        long long res = 0;
        priority_queue<pair<eff, sp>, vector<pair<eff, sp>>, greater<pair<eff, sp>>> q;
        sort(efficiency.begin(), efficiency.end());
        int cur = 0;
        int v_cur = 0;
        long long total_speed = 0;
        while (cur < n)
        {
            while (!q.empty() && q.top().first < efficiency[cur])
            {
                total_speed -= q.top().second;
                q.pop();
            }
            while (q.size() < k && v_cur < n)
            {
                if (v1[v_cur].second >= efficiency[cur])
                {
                    total_speed += v1[v_cur].first;
                    q.push({v1[v_cur].second, v1[v_cur].first});
                }
                v_cur++;
            }
            if (!q.empty())
            {
                res = max(res, total_speed * q.top().first);
            }
            ++cur;
        }
        return res % 1000000007;
    }
};
// @lc code=end
