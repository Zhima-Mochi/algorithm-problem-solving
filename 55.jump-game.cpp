/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        auto back_index = nums.size() - 1;
        while (back_index > 0)
        {
            bool has_bridge = false;
            for (int i = back_index - 1; i >= 0; i--)
            {
                if (nums[i] >= back_index - i)
                {
                    back_index = i;
                    has_bridge = true;
                    break;
                }
            }
            if (!has_bridge)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
