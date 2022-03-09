/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(len(points)^2*log(n)), s:O(len(points))
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int w = points.size();
        int res = 1;
        for (int i = 0; i != w; ++i)
        {
            unordered_map<int, int> records;
            if (w - i <= res)
            {
                break;
            }
            for (int j = i + 1; j != w; ++j)
            {
                int a = points[j][0] - points[i][0];
                int b = points[j][1] - points[i][1];
                int ab_gcd = gcd(a, b);
                a /= ab_gcd;
                b /= ab_gcd;
                ++records[(a + 20000 << 15) + (b + 20000)];
                ++records[(-a + 20000 << 15) + (-b + 20000)];
            }
            for (auto &[k, v] : records)
            {
                res = max(res, v + 1);
            }
        }
        return res;
    }
};
// @lc code=end
