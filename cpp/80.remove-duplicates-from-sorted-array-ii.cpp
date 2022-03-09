/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        auto len = nums.size();
        if (len <= 2)
        {
            return len;
        }
        int left = 1;
        for (int i = 2; i != len; ++i)
        {
            if (nums[i] != nums[left - 1])
            {
                nums[++left] = nums[i];
            }
        }
        return left+1;
        // int left = 0, right = 1;
        // int width = nums.size();
        // while (right != width)
        // {
        //     if (nums[right] == nums[left])
        //     {
        //         nums[++left]=nums[right];
        //         while (++right != width && nums[right] == nums[left])
        //             ;
        //     }
        //     else
        //     {
        //         nums[++left]=nums[right++];
        //     }
        // }
        // return left+1;
    }
};
// @lc code=end
