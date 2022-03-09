/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(Nlog(N)), s:O(1)
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(), [](vector<int> &l, vector<int> &r)
             { return l[0] - l[1] < r[0] - r[1]; });
        int res = 0;
        int w = costs.size();
        for (int i = 0; i != w / 2; ++i)
        {
            res += costs[i][0] + costs[i + w / 2][1];
        }
        return res;
    }
};
// @lc code=end

// t:O(Nlog(N)), s:O(1)
// class Solution
// {
// public:
//     int twoCitySchedCost(vector<vector<int>> &costs)
//     {
//         sort(costs.begin(), costs.end(), [](vector<int> &l, vector<int> &r)
//              { return abs(l[0] - l[1]) > abs(r[0] - r[1]); });
//         int a = costs.size() / 2, b = a;
//         int res = 0;
//         for (auto &cost : costs)
//         {
//             if (cost[0] < cost[1])
//             {
//                 if (a)
//                 {
//                     res += cost[0];
//                     --a;
//                 }
//                 else
//                 {
//                     res += cost[1];
//                     --b;
//                 }
//             }
//             else
//             {
//                 if (b)
//                 {
//                     res += cost[1];
//                     --b;
//                 }
//                 else
//                 {
//                     res += cost[0];
//                     --a;
//                 }
//             }
//         }
//         return res;
//     }
// };