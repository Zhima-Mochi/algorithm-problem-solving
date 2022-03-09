/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int start = sqrt(area) + 0.5;
        while (start != 0)
        {
            if (area % start == 0)
            {
                return {area / start, start};
            }
            --start;
        }
        return {area, 1};
    }
};
// @lc code=end
