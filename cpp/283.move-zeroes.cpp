/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        auto left = 0, right = 0;
        auto len = nums.size();
        while (right != len)
        {
            if (nums[right] != 0)
            {
                swap(nums[left++], nums[right++]);
            }
            else
            {
                ++right;
            }
        }
    }
};
// @lc code=end
