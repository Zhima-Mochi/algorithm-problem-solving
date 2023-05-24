/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(nlogn), s:O(n)
class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> v;
        int w = nums1.size();
        for (int i = 0; i < w; i++)
        {
            v.push_back({nums1[i], nums2[i]});
        }
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.second > b.second; });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long res = 0;
        int current_min = 100000;
        long long current_val = 0;
        for (auto p : v)
        {
            current_min = p.second;
            pq.push(p.first);
            current_val += p.first;
            if (pq.size() > k)
            {
                current_val -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
            {
                res = max(res, current_min * current_val);
            }
        }
        return res;
    }
};
// @lc code=end
