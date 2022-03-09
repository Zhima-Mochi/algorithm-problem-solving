/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int pre_pre = -1;
        int pre = -1;
        for (auto &n : nums)
        {
            if (n == pre_pre || n == pre)
            {
                return n;
            }
            else
            {
                pre_pre = move(pre);
                pre = n;
            }
        }
        return nums[0];
    }
};
// @lc code=end
