/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(log(n))
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int w = nums.size();
        int res = 0;
        for (int i = 0; i != w / 2; ++i)
        {
            res = max(res, nums[i] + nums[w - 1 - i]);
        }
        return res;
    }
};
// @lc code=end
