/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(N^2), s:O(N)
class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        unordered_set<int> seen;
        unordered_map<int, int> x_pos_cnt, y_pos_cnt;
        for (auto &p : points)
        {
            seen.insert((p[0] << 16) + p[1]);
            ++x_pos_cnt[p[0]];
            ++y_pos_cnt[p[1]];
        }
        int res = INT_MAX;
        points.erase(remove_if(points.begin(), points.end(), [&](vector<int> &v)
                               { return x_pos_cnt[v[0]] < 2 || y_pos_cnt[v[1]] < 2; }),
                     points.end());
        int w = points.size();
        for (int i = 0; i < w - 1; ++i)
        {
            for (int j = i + 1; j < w; ++j)
            {
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1])
                {
                    int area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
                    if (area < res && seen.count((points[i][0] << 16) + points[j][1]) && seen.count((points[j][0] << 16) + points[i][1]))
                    {
                        res = area;
                    }
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
