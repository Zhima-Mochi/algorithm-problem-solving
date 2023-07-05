/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */
#include <vector>
#include <deque>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int w = nums.size();
        int res = w + 1;
        vector<long long> accum(w + 1);
        for (int i = 0; i != w; ++i)
        {
            accum[i + 1] = accum[i] + nums[i];
        }
        deque<int> dq;
        for (int i = 0; i != w + 1; ++i)
        {
            while (!dq.empty() && accum[i] - accum[dq.front()] >= k)
            {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && accum[dq.back()] >= accum[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res == w + 1 ? -1 : res;
    }
};
// @lc code=end
