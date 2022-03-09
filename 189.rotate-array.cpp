/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        k %= len;
        if (k == 0)
        {
            return;
        }
        int term = len / k - 1;
        for (int i = 0; i != term; ++i)
        {
            for (int j = 0; j != k; ++j)
            {
                auto pos = len - 1 - k * i - j;
                swap(nums[pos], nums[pos - k]);
            }
        }
        auto left = len % k, right = k;
        auto pos = 0;
        while (left != 0 && right != 0)
        {
            for (int j = 0; j != right; ++j)
            {
                swap(nums[pos + left + j], nums[pos + j]);
            }
            pos += right;
            int val = right % left;
            left -= val;
            right = val;
        }

        return;
    }
};
// @lc code=end
