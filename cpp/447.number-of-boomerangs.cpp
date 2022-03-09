/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        //pos->distance_square->count;
        unordered_map<int, int> count_map;
        int len = points.size();
        int res = 0;
        for (int i = 0; i != len; ++i)
        {
            for (int j = 0; j != len; ++j)
            {
                int distance = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
                ++count_map[distance];
            }
            for (auto &dis_count : count_map)
            {
                res += (dis_count.second * (dis_count.second - 1));
            }
            count_map.clear();
        }

        return res;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     int numberOfBoomerangs(vector<vector<int>> &points)
//     {
//         //pos->distance_square->count;
//         unordered_map<int, unordered_map<int, int>> count_map;
//         int len = points.size();
//         for (int i = 0; i != len - 1; ++i)
//         {
//             for (int j = i+1; j != len; ++j)
//             {
//                 int distance = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
//                 ++count_map[(points[i][0] * (1 << 15)) + points[i][1]][distance];
//                 ++count_map[(points[j][0] * (1 << 15)) + points[j][1]][distance];
//             }
//         }
//         int res = 0;
//         for (auto &pos_dis : count_map)
//         {
//             for (auto &dis_count : pos_dis.second)
//             {
//                 res += (dis_count.second * (dis_count.second - 1));
//             }
//         }
//         return res;
//     }
// };