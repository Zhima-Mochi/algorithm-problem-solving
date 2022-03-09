/*
 * @lc app=leetcode id=2099 lang=cpp
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0, w = nums.size(); i != w; ++i)
        {
            pq.push({nums[i], i});
            if (pq.size() == k + 1)
            {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        for (auto &n : res)
        {
            n = nums[n];
        }
        return res;
    }
};
// @lc code=end
