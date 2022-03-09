/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */
#include <cmath>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        return (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1) - max(((ay2 - ay1) + (by2 - by1) - (max(ay2, by2) - min(ay1, by1))), 0) * max(((ax2 - ax1) + (bx2 - bx1) - (max(ax2, bx2) - min(ax1, bx1))), 0);
    }
};
// @lc code=end
