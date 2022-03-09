/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int len = nums.size();
        nth_element(nums.begin(), nums.begin() + (len - 1) / 2, nums.end());
        swap(nums[(len - 1) / 2], nums[0]);

        int lower_cur = len - ((len + 1) % 2) - 1, cur = lower_cur, upper_cur = 1;
        for (int i = 0; i < len && upper_cur != cur + 2; ++i)
        {
            if (nums[cur] < nums[0])
            {
                swap(nums[lower_cur], nums[cur]);
                cur -= 2;
                lower_cur -= 2;
                if (cur < 0)
                {
                    cur = len - (len % 2) - 1;
                }
            }
            else if (nums[cur] > nums[0])
            {
                swap(nums[cur], nums[upper_cur]);
                upper_cur += 2;
            }
            else
            {
                cur -= 2;
                if (cur < 0)
                {
                    cur = len - (len % 2) - 1;
                }
            }
        }
    }
};
// @lc code=end
// class Solution
// {
// public:
//     void wiggleSort(vector<int> &nums)
//     {
//         int len = nums.size();
//         auto copy_n = nums;
//         sort(copy_n.begin(), copy_n.end(), greater<int>());
//         for (int i = 0; i < len; i += 2)
//         {
//             nums[i] = copy_n[len / 2 + i / 2];
//         }
//         for (int i = 1; i < len; i += 2)
//         {
//             nums[i] = copy_n[i / 2];
//         }
//     }
// };