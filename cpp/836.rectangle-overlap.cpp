/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
};
// @lc code=end
