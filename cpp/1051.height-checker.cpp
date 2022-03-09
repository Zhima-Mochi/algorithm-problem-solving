/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        auto heights2 = heights;
        sort(heights2.begin(), heights2.end());
        int width = heights.size();
        int count = 0;
        for (int i = 0; i != width; ++i)
        {
            if (heights2[i] != heights[i])
            {
                ++count;
            }
        }
        //can use counting sort
        return count;
    }
};
// @lc code=end
