/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int len = nums.size();
        if (len % 2 == 0)
        {
            return true;
        }

        return PredictTheWinner(nums, 0, len - 1, 0);
    }
    bool PredictTheWinner(vector<int> &nums, int left, int right, int base)
    {
        if (left == right)
        {
            return base + nums[left] >= 0;
        }
        else
        {
            if ((PredictTheWinner(nums, left + 2, right, base + nums[left] - nums[left + 1]) && PredictTheWinner(nums, left + 1, right - 1, base + nums[left] - nums[right])) || (PredictTheWinner(nums, left + 1, right - 1, base + nums[right] - nums[left]) && PredictTheWinner(nums, left, right - 2, base + nums[right] - nums[right - 1])))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
// @lc code=end
