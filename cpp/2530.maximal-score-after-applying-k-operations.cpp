/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (auto n : nums)
        {
            pq.push(n);
        }
        long long res = 0;
        while (k)
        {
            auto val = pq.top();
            pq.pop();
            res += val;
            pq.push((val + 2) / 3);
            k -= 1;
        }
        return res;
    }
};
// @lc code=end
