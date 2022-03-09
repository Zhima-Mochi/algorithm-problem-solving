/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int length;

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum_val = accumulate(nums.begin(), nums.end(), 0);
        if (sum_val % k)
        {
            return false;
        }
        length = nums.size();
        int required_num = sum_val / k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> subset(k);
        return backtrack(subset, k, required_num, nums, 0);
    }
    bool backtrack(vector<int> &subset, const int k, const int required_num, vector<int> &nums, int pos)
    {
        if (pos == length)
        {
            return true;
        }
        for (int i = 0; i != k; ++i)
        {
            bool seen = false;
            for (int j = 0; j != i; ++j)
            {
                if (subset[i] == subset[j])
                {
                    seen = true;
                    break;
                }
            }
            if (seen || subset[i] + nums[pos] > required_num)
            {
                continue;
            }
            subset[i] += nums[pos];
            if (backtrack(subset, k, required_num, nums, pos + 1))
            {
                return true;
            }
            subset[i] -= nums[pos];
        }
        return false;
    }
};
// @lc code=end
