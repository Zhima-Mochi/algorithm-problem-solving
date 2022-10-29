/*
 * @lc app=leetcode id=2136 lang=cpp
 *
 * [2136] Earliest Possible Day of Full Bloom
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int res = 0;
        int w = plantTime.size();
        auto comp = [&](pair<int, int> &i, pair<int, int> &j)
        {
            return i.first + max(i.second, j.first + j.second) > j.first + max(j.second, i.first + i.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
        for (int i = 0; i != w; ++i)
        {
            q.push({plantTime[i], growTime[i]});
        }
        int plantSum = 0;
        while (q.size())
        {
            auto elem = q.top();
            q.pop();
            plantSum += elem.first;
            res = max(res, plantSum + elem.second);
        }
        return res;
    }
};
// @lc code=end
