/*
 * @lc app=leetcode id=2012 lang=cpp
 *
 * [2012] Sum of Beauty in the Array
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        int w = nums.size();
        vector<int> left_max(w), right_min(w);
        left_max[0] = nums[0];
        right_min[w - 1] = nums.back();
        int res = 0;
        for (int i = 1; i != w - 1; ++i)
        {
            left_max[i] = max(left_max[i - 1], nums[i]);
            right_min[w - 1 - i] = min(right_min[w - i], nums[w - 1 - i]);
        }
        for (int i = w - 2; i != 0; --i)
        {
            if (nums[i] < nums[i + 1] && nums[i] > nums[i - 1])
            {
                if (nums[i] < right_min[i + 1] && nums[i] > left_max[i - 1])
                {
                    res += 2;
                }
                else
                {
                    res += 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
