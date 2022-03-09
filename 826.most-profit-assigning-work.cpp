/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        auto comp = [](pair<int, int> &l, pair<int, int> &r)
        {
            if (l.first < r.first)
            {
                return true;
            }
            else if (l.first == r.first)
            {
                return l.second > r.second;
            }
            else
            {
                return false;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
        int width = difficulty.size();
        for (int i = 0; i != width; ++i)
        {
            q.push({profit[i], difficulty[i]});
        }
        sort(worker.begin(), worker.end(), greater<int>());
        int res = 0;
        int ind = 0;
        int worker_num = worker.size();
        while (ind != worker_num && !q.empty())
        {
            if (worker[ind] >= q.top().second)
            {
                res += q.top().first;
                ++ind;
            }
            else
            {
                q.pop();
            }
        }
        return res;
    }
};
// @lc code=end
