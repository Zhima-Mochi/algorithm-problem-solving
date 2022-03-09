/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        nums.push_back(1000000);
        int width = nums.size();
        if (width < 4)
        {
            return 0;
        }
        int res = 0;
        int count = 0;
        int step = nums[1] - nums[0];
        for (auto i = 2; i != width; ++i)
        {
            if (nums[i] - nums[i - 1] == step)
            {
                ++count;
            }
            else
            {
                res += (count + 1) * count / 2;
                count = 0;
                step = nums[i] - nums[i - 1];
            }
        }
        return res;
    }
};
// @lc code=end
