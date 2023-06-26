/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(klog(c)), s:O(c)
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<int> left_q, right_q;
        int l = 0;
        int r = costs.size() - 1;
        long long res = 0;
        while (k)
        {
            if (l <= r && left_q.size() < candidates)
            {
                left_q.push(-costs[l++]);
                continue;
            }
            if (l <= r && right_q.size() < candidates)
            {
                right_q.push(-costs[r--]);
                continue;
            }
            if (right_q.empty() || !left_q.empty() && left_q.top() >= right_q.top())
            {
                res -= left_q.top();
                left_q.pop();
            }
            else
            {
                res -= right_q.top();
                right_q.pop();
            }
            --k;
        }
        return res;
    }
};
// @lc code=end
