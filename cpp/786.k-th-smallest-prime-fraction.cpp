/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(klog(n)), s:O(n)
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        auto comp = [&](pair<int, int> &a, pair<int, int> b)
        {
            return a.first * 1.0 / arr[a.second] > b.first * 1.0 / arr[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
            pq(comp);
        int w = arr.size();
        for (auto n : arr)
        {
            pq.push({n, w - 1});
        }
        while (--k)
        {
            auto top = pq.top();
            pq.pop();
            if (top.first == arr[top.second - 1])
            {
                top.second -= 2;
            }
            else
            {
                top.second -= 1;
            }
            if (top.second >= 0)
            {
                pq.push(top);
            }
        }
        return vector<int>{pq.top().first, arr[pq.top().second]};
    }
};
// @lc code=end
