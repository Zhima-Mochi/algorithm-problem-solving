/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        vector<int> arrive_time;
        int w = dist.size();
        for (int i = 0; i != w; ++i)
        {
            if (dist[i] % speed[i] == 0)
            {
                arrive_time.push_back(dist[i] / speed[i]);
            }
            else
            {
                arrive_time.push_back(dist[i] / speed[i] + 1);
            }
        }
        sort(arrive_time.begin(), arrive_time.end());
        int time = 0;
        for (; time != w; ++time)
        {
            if (arrive_time[time] <= time)
            {
                break;
            }
        }
        return time;
    }
};
// @lc code=end
