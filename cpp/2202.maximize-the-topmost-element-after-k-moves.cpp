/*
 * @lc app=leetcode id=2202 lang=cpp
 *
 * [2202] Maximize the Topmost Element After K Moves
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int maximumTop(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return nums[0];
        }
        int n = nums.size();
        if (k == 1)
        {
            if (n == 1)
            {
                return -1;
            }
            else
            {
                return nums[1];
            }
        }
        if (n == 1)
        {
            if (k % 2)
            {
                return -1;
            }
            else
            {
                return nums[0];
            }
        }
        if (n >= k - 1)
        {
            return max(*max_element(nums.begin(), nums.begin() + k - 1), nums[k]);
        }
        return *max_element(nums.begin(), nums.end());
    }
};
// @lc code=end
