/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());//or selection sort or make heap...
        int len = nums.size();
        int c1 = nums[0] * nums[1] * nums[len - 1];
        int c2 = nums[len - 1] * nums[len - 2] * nums[len - 3];
        return c1 > c2 ? c1 : c2;
    }
};
// @lc code=end
