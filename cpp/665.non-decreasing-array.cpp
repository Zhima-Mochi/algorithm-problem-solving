/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int error_num = 0;
        int width = nums.size();
        for (int i = 1; i != width; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                ++error_num;
                if (error_num > 1)
                {
                    return false;
                }
                if ((i < width - 1 && nums[i + 1] < nums[i - 1]) && (i != 1 && nums[i] < nums[i - 2]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
