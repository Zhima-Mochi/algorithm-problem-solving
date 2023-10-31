/*
 * @lc app=leetcode id=2221 lang=cpp
 *
 * [2221] Find Triangular Sum of an Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        while (nums.size() > 1)
        {
            int n = nums.size();
            for (int i = 0; i != n - 1; ++i)
            {
                nums[i] += nums[i + 1];
                nums[i] %= 10;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};
// @lc code=end
