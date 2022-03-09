/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> q;
        int res = INT_MAX;
        int min_val = INT_MAX;
        for (auto n : nums)
        {
            n = n % 2 ? 2 * n : n;
            q.push(n);
            min_val = min(min_val, n);
        }
        while (!(q.top() % 2))
        {
            res = min(res, q.top() - min_val);
            min_val = min(min_val, q.top() / 2);
            q.push(q.top() / 2);
            q.pop();
        }
        res = min(res, q.top() - min_val);
        return res;
    }
};
// @lc code=end
