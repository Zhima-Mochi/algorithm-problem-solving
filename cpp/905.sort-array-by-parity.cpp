/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[right] % 2 == 0)
            {
                swap(nums[left], nums[right]);
                ++left;
            }
            else
            {
                --right;
            }
        }
        return nums;
    }
};
// @lc code=end
