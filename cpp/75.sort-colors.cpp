/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        auto width = nums.size();
        int left = 0, right = width - 1;
        while (right >= 0 && nums[right] == 2)
        {
            --right;
        }
        while (left < width && nums[left] == 0)
        {
            ++left;
        }

        for (int i = left; i < right + 1; i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[left++]);
                while (left < width && nums[left] == 0)
                {
                    ++left;
                }
            }
            else if (nums[i] == 1)
            {
                continue;
            }
            else
            {
                swap(nums[i], nums[right--]);
                while (right >= 0 && nums[right] == 2)
                {
                    --right;
                }
                if (nums[i] == 0)
                {
                    swap(nums[i], nums[left++]);
                }
            }
        }
    }
};
// @lc code=end
