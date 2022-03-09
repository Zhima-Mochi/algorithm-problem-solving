/*
 * @lc app=leetcode id=963 lang=cpp
 *
 * [963] Minimum Area Rectangle II
 */
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <climits>
using namespace std;
// @lc code=start

// t:O(n^2log(n)), s:O(n^2)
// https://en.wikipedia.org/wiki/Sum_of_squares_function#Particular_cases
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
class Solution
{
public:
    unordered_set<int> points_pos;
    double minAreaFreeRect(vector<vector<int>> &points)
    {
        int w = points.size();
        unordered_map<int, unordered_map<pair<int, int>, vector<pair<int, int>>, hash_pair>> record;
        for (int i = 0; i != w - 1; ++i)
        {
            for (int j = i + 1; j != w; ++j)
            {
                pair<int, int> center = {points[i][0] + points[j][0], points[i][1] + points[j][1]};
                int len2 = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
                record[len2][center].push_back({points[i][0], points[i][1]});
            }
        }
        double res = 0;
        for (auto &[len2, up] : record)
        {
            for (auto &[center, pts] : up)
            {
                int pts_w = pts.size();
                for (int i = 0; i != pts_w - 1; ++i)
                {
                    for (int j = i + 1; j != pts_w; ++j)
                    {
                        if (res == 0)
                        {
                            res = get_area(pts[i], pts[j], center);
                        }
                        else
                        {
                            res = min(res, get_area(pts[i], pts[j], center));
                        }
                    }
                }
            }
        }
        return res;
    }
    double get_area(const pair<int, int> &pos_1, const pair<int, int> &pos_2, const pair<int, int> &center)
    {
        long long dist_1 = pow(pos_1.first - pos_2.first, 2) + pow(pos_1.second - pos_2.second, 2);
        pair<int, int> pos_3 = {center.first - pos_1.first, center.second - pos_1.second};
        long long dist_2 = pow(pos_3.first - pos_2.first, 2) + pow(pos_3.second - pos_2.second, 2);
        return pow(dist_1 * dist_2, 0.5);
    }
};
// @lc code=end
