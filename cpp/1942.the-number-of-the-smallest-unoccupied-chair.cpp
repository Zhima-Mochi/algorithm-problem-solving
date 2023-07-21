/*
 * @lc app=leetcode id=1942 lang=cpp
 *
 * [1942] The Number of the Smallest Unoccupied Chair
 */
#include <vector>
#include <queue>
#include <set>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(n)
class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int target_arrive = times[targetFriend][0];
        sort(times.begin(), times.end(), [&](vector<int> &l, vector<int> &r)
             { return l[0] < r[0]; });
        int w = times.size();
        set<int> unused;
        for (int i = 0; i != w; ++i)
        {
            unused.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            pq;
        for (auto &time : times)
        {
            while (!pq.empty() && pq.top().first <= time[0])
            {
                unused.insert(pq.top().second);
                pq.pop();
            }
            int cur = *unused.begin();

            if (time[0] == target_arrive)
            {
                return cur;
            }
            unused.erase(cur);
            pq.push({time[1], cur});
        }
        return -1;
    }
};
// @lc code=end
