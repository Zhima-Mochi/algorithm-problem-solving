/*
 * @lc app=leetcode id=1995 lang=cpp
 *
 * [1995] Count Special Quadruplets
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countQuadruplets(vector<int> &nums)
    {
        unordered_map<int, int> value_count;
        int width = nums.size();
        int res = 0;
        for (int i = 1; i < width; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                ++value_count[nums[j] + nums[i]];
            }
            for (int k = i + 2; k < width; ++k)
            {
                if (value_count.count(nums[k] - nums[i + 1]))
                {
                    res += value_count[nums[k] - nums[i + 1]];
                }
            }
        }
        return res;
    }
};
// @lc code=end
