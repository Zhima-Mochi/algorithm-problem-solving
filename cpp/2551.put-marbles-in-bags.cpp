/*
 * @lc app=leetcode id=2551 lang=cpp
 *
 * [2551] Put Marbles in Bags
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(nlog(k)), s:O(k);
class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int w = weights.size();
        if (w == 1)
        {
            return 0;
        }
        priority_queue<long long> pq_min;
        priority_queue<long long, vector<long long>, greater<long long>> pq_max;
        if (2 * (k - 1) > w - 1)
        {
            k -= (2 * (k - 1) - (w - 1));
        }
        for (int i = 1; i != w; ++i)
        {
            pq_min.push(weights[i] + weights[i - 1]);
            pq_max.push(weights[i] + weights[i - 1]);
            if (pq_min.size() == k)
            {
                pq_min.pop();
                pq_max.pop();
            }
        }
        long long res = 0;
        while (!pq_max.empty())
        {
            res += pq_max.top();
            pq_max.pop();
        }
        while (!pq_min.empty())
        {
            res -= pq_min.top();
            pq_min.pop();
        }
        return res;
    }
};
// @lc code=end
