/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            if ((mid - left) % 2)
            {
                if (nums[mid] == nums[mid + 1])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] != nums[mid + 1])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 2;
                }
            }
        }
        return nums[left];
    }
};
// @lc code=end
