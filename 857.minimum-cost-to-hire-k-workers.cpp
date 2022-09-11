/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<int> h(n, 0);
        iota(h.begin(), h.end(), 0);
        sort(h.begin(), h.end(), [&](int &l, int &r)
             { return quality[l] * wage[r] > quality[r] * wage[l]; });
        double res = 1000000000;
        double total = 0.0;
        priority_queue<int> q;
        for (int i = 0; i < k - 1; i++)
        {
            total += quality[h[i]];
            q.push(quality[h[i]]);
        }
        for (int i = k - 1; i < n; i++)
        {
            int idx = h[i];
            total += quality[idx];
            q.push(quality[idx]);
            double val = (wage[idx] * 1.0 / quality[idx]) * total;
            res = min(res, val);
            total -= q.top();
            q.pop();
        }
        return res;
    }
};
// @lc code=end
