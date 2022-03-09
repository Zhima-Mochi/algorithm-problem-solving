/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (((1 + k) * k) / 2 > n || n > 45)
        {
            return vector<vector<int>>();
        }
        queue<vector<int>> q;
        queue<int> q_sum;
        q.push(vector<int>{0});
        q_sum.push(0);
        while (!q.empty() && q.front().size() < k + 1)
        {
            int q_len = q.size();
            while (q_len)
            {
                auto cur = q.front();
                auto cur_sum = q_sum.front();
                q.pop();
                q_sum.pop();
                for (int i = cur.back() + 1; i <= 9 && cur_sum + i <= n; ++i)
                {
                    q.push(cur);
                    q.back().push_back(i);
                    q_sum.push(cur_sum + i);
                }
                --q_len;
            }
        }
        vector<vector<int>> res;
        while (!q.empty())
        {
            if (q_sum.front() == n)
            {
                res.emplace_back(q.front().begin() + 1, q.front().end());
            }
            q.pop();
            q_sum.pop();
        }
        return res;
    }
};
// @lc code=end
