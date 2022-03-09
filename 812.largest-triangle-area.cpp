/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int len = points.size();
        int res = 0;
        for (int i = 0; i != len - 2; ++i)
        {
            for (int j = i + 1; j != len - 1; ++j)
            {
                for (int k = j + 1; k != len; ++k)
                {
                    int a = points[j][0] - points[i][0];
                    int b = points[j][1] - points[i][1];
                    int c = points[k][0] - points[i][0];
                    int d = points[k][1] - points[i][1];
                    res = max(abs(a * d - b * c), res);
                }
            }
        }
        return 0.5 * static_cast<double>(res);
    }
};
// @lc code=end
