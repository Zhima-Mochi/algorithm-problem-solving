/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        auto len = nums.size();
        size_t left = 0, right = len - 1;
        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
