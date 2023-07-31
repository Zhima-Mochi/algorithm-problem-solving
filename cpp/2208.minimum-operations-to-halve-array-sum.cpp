/*
 * @lc app=leetcode id=2208 lang=cpp
 *
 * [2208] Minimum Operations to Halve Array Sum
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(nlogn), s:O(n)
class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        priority_queue<double> pq;
        double sum = 0;
        int w = nums.size();
        for (int i = 0; i != w; ++i)
        {
            pq.push(nums[i]);
            sum += nums[i];
        }
        double cur_sum = sum;
        int res = 0;
        while (cur_sum > sum / 2)
        {
            res++;
            double n = pq.top();
            pq.pop();
            n /= 2;
            cur_sum -= n;
            pq.push(n);
        }
        return res;
    }
};
// @lc code=end
