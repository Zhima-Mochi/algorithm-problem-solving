/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 */
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
#define mod 1000000007
class Solution
{
public:
    int rectangleArea(vector<vector<int>> &rectangles)
    {
        int width = rectangles.size();
        vector<int> x_point;
        x_point.reserve(2 * width);
        for (auto &r : rectangles)
        {
            x_point.push_back(r[0]);
            x_point.push_back(r[2]);
        }
        sort(x_point.begin(), x_point.end());
        auto end_unique = unique(x_point.begin(), x_point.end());
        x_point.erase(end_unique, x_point.end());
        int x_point_width = x_point.size();
        unordered_map<int, int> x_index;
        for (int i = 0; i != x_point_width; ++i)
        {
            x_index[x_point[i]] = i;
        }
        vector<int> count(x_point_width, 0);
        vector<vector<int>> L;
        for (auto r : rectangles)
        {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            L.push_back({y1, x1, x2, 1});
            L.push_back({y2, x1, x2, -1});
        }
        sort(L.begin(), L.end());

        long cur_y = 0, cur_x_sum = 0, res = 0;
        for (auto &l : L)
        {
            const int &y = l[0], &x1 = l[1], &x2 = l[2], &sig = l[3];
            res += (y - cur_y) * cur_x_sum % mod;
            res %= mod;
            cur_y = y;
            if (sig == 1)
            {
                for (int i = x_index[x1]; i != x_index[x2]; ++i)
                {
                    if (++count[i] == 1)
                    {
                        cur_x_sum += x_point[i + 1] - x_point[i];
                    }
                }
            }
            else
            {
                for (int i = x_index[x1]; i != x_index[x2]; ++i)
                {
                    if (--count[i] == 0)
                    {
                        cur_x_sum -= x_point[i + 1] - x_point[i];
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int rectangleArea(vector<vector<int>> &rectangles)
//     {
//         long res = 0;

//         int width = rectangles.size();
//         map<int, map<int, bool>> point;
//         map<int, bool> y_point;
//         for (auto &vec : rectangles)
//         {
//             point[vec[0]];
//             point[vec[2]];
//             y_point[vec[1]];
//             y_point[vec[3]];
//         }
//         for (auto &pair : point)
//         {
//             pair.second = y_point;
//         }
//         for (auto &rec : rectangles)
//         {
//             for (auto x_iter = point.find(rec[0]), iterEnd = point.find(rec[2]); x_iter != iterEnd; ++x_iter)
//             {
//                 for (auto y_iter = x_iter->second.find(rec[1]), iterEnd = x_iter->second.find(rec[3]); y_iter != iterEnd; ++y_iter)
//                 {
//                     if (!y_iter->second)
//                     {
//                         y_iter->second = true;
//                         res += (static_cast<long long>(next(x_iter)->first - x_iter->first) * static_cast<long long>(next(y_iter)->first - y_iter->first)) % mod;
//                         res %= mod;
//                     }
//                 }
//             }
//         }

//         return res;
//     }
// };