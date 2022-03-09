/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (len <= 2)
        {
            return 0;
        }
        int res = 0;
        for (int k = len - 1; k != 1; k--)
        {
            int i = 0, j = k - 1;

            while (i != j)
            {
                if (nums[j] + nums[i] > nums[k])
                {
                    res+=j-i;
                    --j;
                }
                else
                {
                    ++i;
                }
            }
        }
        return res;
    }
};
// @lc code=end
