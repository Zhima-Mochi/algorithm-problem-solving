/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> dp_length(len, 1);
        vector<int> dp_count(len, 1);
        for (int i = len - 1; i != -1; --i)
        {
            for (int j = i + 1; j != len; ++j)
            {
                if (nums[j] > nums[i])
                {
                    if (dp_length[j] + 1 > dp_length[i])
                    {
                        dp_length[i] = dp_length[j] + 1;
                        dp_count[i] = dp_count[j];
                    }
                    else if (dp_length[j] + 1 == dp_length[i])
                    {
                        dp_count[i] += dp_count[j];
                    }
                }
            }
        }
        int res = 0;
        int max_length = *max_element(dp_length.begin(), dp_length.end());
        for (int i = 0; i != len; ++i)
        {
            if (dp_length[i] == max_length)
            {
                res += dp_count[i];
            }
        }
        return res;
    }
};
// @lc code=end
