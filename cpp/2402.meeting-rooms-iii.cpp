/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(mlog(m)+mlog(n)+n), s:O(log(m)+n)
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        unordered_map<int, int> used_cnt;
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;
        for (int i = 0; i != n; ++i)
        {
            free.push(i);
        }
        sort(meetings.begin(), meetings.end());
        long long time = 0;
        for (auto &meet : meetings)
        {
            time = max(time, static_cast<long long>(meet[0]));
            while (!used.empty() && used.top().first <= time)
            {
                free.push(used.top().second);
                used.pop();
            }
            if (free.empty())
            {
                time = used.top().first;
                while (!used.empty() && used.top().first <= time)
                {
                    free.push(used.top().second);
                    used.pop();
                }
            }
            used_cnt[free.top()] += 1;
            used.push({time + meet[1] - meet[0], free.top()});
            free.pop();
        }
        int res = 0;
        int current_max = 0;
        for (auto &[roomID, cnt] : used_cnt)
        {
            if (cnt > current_max)
            {
                res = roomID;
                current_max = cnt;
            }
            else if (cnt == current_max)
            {
                res = min(res, roomID);
            }
        }
        return res;
    }
};
// @lc code=end
