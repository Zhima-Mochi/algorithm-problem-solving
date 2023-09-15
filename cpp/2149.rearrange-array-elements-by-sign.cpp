/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int cur0 = 0, cur1 = 1;
        for (int i = 0; i != n; ++i)
        {
            if (nums[i] > 0)
            {
                res[cur0] = nums[i];
                cur0 += 2;
            }
            else
            {
                res[cur1] = nums[i];
                cur1 += 2;
            }
        }
        return res;
    }
};
// @lc code=end
