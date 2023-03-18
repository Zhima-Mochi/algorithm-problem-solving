/*
 * @lc app=leetcode id=1882 lang=cpp
 *
 * [1882] Process Tasks Using Servers
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(mlog(n)+m), s:O(n)
class Solution
{
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> notAvailable;
        int w = servers.size();
        for (int i = 0; i != w; ++i)
        {
            available.push({servers[i], i});
        }
        int cur = 0;
        int right = 0;
        int wt = tasks.size();
        int time = 0;
        while (cur < wt)
        {
            ++time;
            if (available.empty())
            {
                time = notAvailable.top().first;
            }
            while (!notAvailable.empty() && notAvailable.top().first <= time)
            {
                auto elem = notAvailable.top().second;
                notAvailable.pop();
                available.push({servers[elem], elem});
            }
            while (!available.empty() && cur < time && cur < wt)
            {
                res.push_back(available.top().second);
                notAvailable.push({tasks[cur] + time, available.top().second});
                cur++;
                available.pop();
            }
        }
        return res;
    }
};
// @lc code=end
