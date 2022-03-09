/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        auto [a, b] = make_pair(points[1][0] - points[0][0], points[1][1] - points[0][1]);
        auto [c, d] = make_pair(points[2][0] - points[1][0], points[2][1] - points[1][1]);
        if (b * c == a * d)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
