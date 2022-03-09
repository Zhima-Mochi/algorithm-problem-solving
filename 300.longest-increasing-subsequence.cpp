/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> tail_value = {nums[0]};
        auto len = nums.size();
        for (int i = 1; i != len; ++i)
        {
            int left = 0;
            int right = tail_value.size();
            if (nums[i] > tail_value.back())
            {
                tail_value.push_back(nums[i]);
            }
            else
            {
                while (left < right)
                {
                    auto mid = left + (right - left) / 2;
                    if (tail_value[mid] < nums[i])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid;
                    }
                }
                tail_value[left] = nums[i];
            }
        }
        return tail_value.size();
    }
};
// @lc code=end
