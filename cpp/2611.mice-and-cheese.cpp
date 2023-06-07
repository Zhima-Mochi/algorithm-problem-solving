/*
 * @lc app=leetcode id=2611 lang=cpp
 *
 * [2611] Mice and Cheese
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(nlogk) s:O(k)
class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        int w = reward1.size();
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < w; i++)
        {
            res += reward2[i];
            q.push(reward1[i] - reward2[i]);
            if (q.size() > k)
            {
                q.pop();
            }
        }
        while (!q.empty())
        {
            res += q.top();
            q.pop();
        }
        return res;
    }
};
// @lc code=end
