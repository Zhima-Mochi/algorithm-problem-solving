/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a - b != 0)
            {
                q.push(a - b);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};
// @lc code=end
