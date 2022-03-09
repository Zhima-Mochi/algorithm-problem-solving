/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        size_t pos = -1;
        auto len = nums.size();
        for (auto i = len - 2; i != -1; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            size_t left = pos + 1;
            size_t right = len - 1;
            auto &pos_val = nums[pos];
            if (pos_val < nums[right])
            {
                swap(pos_val, nums[right]);
            }
            else
            {
                while (right - left != 1)
                {
                    auto middle = left + (right - left) / 2;
                    if (nums[middle] > pos_val)
                    {
                        left = middle;
                    }
                    else
                    {
                        right = middle;
                    }
                }
                swap(pos_val, nums[left]);
            }
            reverse(nums.begin()+pos+1,nums.end());
            // for (int i = pos + 1; i < pos + 1 + (len - (pos + 1)) / 2; i++)
            // {
            //     swap(nums[i], nums[len - (i - (pos + 1)) - 1]);
            // }
        }
    }
};
// @lc code=end
