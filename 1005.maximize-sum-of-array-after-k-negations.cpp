/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, len = nums.size(); i != len; ++i)
        {
            if (k)
            {
                if (nums[i] < 0)
                {
                    res -= nums[i];
                    --k;
                }
                else
                {
                    k %= 2;
                    if (k)
                    {
                        if (i && -nums[i - 1] < nums[i])
                        {
                            res += 2 * nums[i - 1];
                            res += nums[i];
                        }
                        else
                        {
                            res -= nums[i];
                        }
                        --k;
                    }
                    else
                    {
                        res += nums[i];
                    }
                }
            }
            else
            {
                res += nums[i];
            }
        }
        k %= 2;
        if (k)
        {
            res += 2 * nums.back();
        }
        return res;
    }
};
// @lc code}
