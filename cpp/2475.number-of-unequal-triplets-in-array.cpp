/*
 * @lc app=leetcode id=2475 lang=cpp
 *
 * [2475] Number of Unequal Triplets in Array
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int unequalTriplets(vector<int> &nums)
    {
        int w = nums.size();
        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            for (int j = i + 1; j != w; ++j)
            {
                if (nums[j] == nums[i])
                {
                    continue;
                }
                for (int k = j + 1; k != w; ++k)
                {
                    if (nums[i] == nums[k] || nums[j] == nums[k])
                    {
                        continue;
                    }
                    res += 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
