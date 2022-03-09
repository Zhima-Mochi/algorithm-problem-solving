/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        for (int i = 0, width = nums.size(); i != width; ++i)
        {
            if (nums[i] != i)
            {
                if (nums[i] > i + 1)
                {
                    return false;
                }
                else if (nums[i + 1] != i)
                {
                    return false;
                }
                ++i;
            }
        }
        return true;
    }
};
// @lc code=end
