/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int high_n = 1, low_n = 1;
        int width = nums.size();
        for (int i = 1; i != width; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                high_n = low_n + 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                low_n = high_n + 1;
            }
        }
        return max(high_n, low_n);
    }
};
// @lc code=end
// class Solution
// {
// public:
//     int wiggleMaxLength(vector<int> &nums)
//     {
//         int width = nums.size();
//         vector<int> up_pos(width, 1), low_pos(width, 1);
//         int res = 1;

//         for (auto i = 0; i != width - 1; ++i)
//         {
//             for (auto j = i + 1; j != width; ++j)
//             {
//                 if (nums[j] > nums[i])
//                 {
//                     up_pos[j] = max(up_pos[j], low_pos[i] + 1);
//                 }
//                 else if (nums[j] < nums[i])
//                 {
//                     low_pos[j] = max(low_pos[j], up_pos[i] + 1);
//                 }
//                 res = max({up_pos[j], low_pos[j], res});
//             }
//         }
//         return res;
//     }
// };