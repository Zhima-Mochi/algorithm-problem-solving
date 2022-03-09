/*
 * @lc app=leetcode id=2057 lang=cpp
 *
 * [2057] Smallest Index With Equal Value
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int smallestEqual(vector<int> &nums)
    {
        for (int i = 0, w = nums.size(); i != w; ++i)
        {
            if (nums[i] == i % 10)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
