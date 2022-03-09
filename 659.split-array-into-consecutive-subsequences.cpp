/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pos_len_queue;
        for (auto n : nums)
        {
            while (!pos_len_queue.empty() && n > pos_len_queue.top().first + 1 && pos_len_queue.top().second >= 3)
            {
                pos_len_queue.pop();
            }
            if (pos_len_queue.empty())
            {
                pos_len_queue.push({n, 1});
            }
            else if (n == pos_len_queue.top().first)
            {
                pos_len_queue.push({n, 1});
            }
            else if (n == pos_len_queue.top().first + 1)
            {
                auto elem = pos_len_queue.top();
                pos_len_queue.pop();
                pos_len_queue.push({n, elem.second + 1});
            }
            else
            {
                return false;
            }
        }
        while (!pos_len_queue.empty())
        {
            if (pos_len_queue.top().second < 3)
            {
                return false;
            }
            pos_len_queue.pop();
        }
        return true;
    }
};
// @lc code=end
