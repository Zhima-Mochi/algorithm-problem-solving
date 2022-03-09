/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int width = nums.size();
        if (width <= nums[0])
        {
            return width;
        }
        int left = 1, right = width - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (width - mid > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return width - left > nums[left - 1] && width - left <= nums[left] ? width - left : -1;
    }
};
// @lc code=end
