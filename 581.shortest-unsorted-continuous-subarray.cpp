/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int width = nums.size();
        int max_val = nums[0];
        int min_val = nums[width - 1];
        int start = 0, tail = -1;
        for (int i = 0; i != width; ++i)
        {
            if (max_val > nums[i])
            {
                tail = i;
            }
            else
            {
                max_val = nums[i];
            }
            if (min_val < nums[width - 1 - i])
            {
                start = width - 1 - i;
            }
            else
            {
                min_val = nums[width - 1 - i];
            }
        }
        return tail - start + 1;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int findUnsortedSubarray(vector<int> &nums)
//     {
//         int val_stack_index = -1;
//         int res = 0;
//         int width = nums.size();
//         int cur_max = 0;
//         int pos = 0;
//         for (auto n : nums)
//         {
//             ++pos;
//             if (val_stack_index == -1 || n >= nums[val_stack_index])
//             {
//                 val_stack_index = pos - 1;
//             }
//             else
//             {
//                 cur_max = nums[val_stack_index];
//                 ++res;
//                 while (val_stack_index != -1 && n < nums[val_stack_index])
//                 {
//                     --val_stack_index;
//                     ++res;
//                 }
//                 break;
//             }
//         }
//         int next_accum = 0;
//         while (pos != width)
//         {
//             ++next_accum;
//             if (nums[pos] >= cur_max)
//             {
//                 cur_max = nums[pos];
//             }
//             else
//             {
//                 res += next_accum;
//                 next_accum = 0;
//                 while (val_stack_index != -1 && nums[pos] < nums[val_stack_index])
//                 {
//                     --val_stack_index;
//                     ++res;
//                 }
//             }
//             ++pos;
//         }

//         return res;
//     }
// };