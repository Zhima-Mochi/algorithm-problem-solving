/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int w = nums.size();
        for (int i = 0; i != w; ++i)
        {
            while (nums[i] > 0 && nums[i] != i + 1 && nums[i] - 1 < w)
            {
                if (nums[i] == nums[nums[i] - 1])
                {
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i != w; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return w + 1;
    }
};
// @lc code=end
