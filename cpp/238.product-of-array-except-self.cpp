/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        bool has_zero = false;
        int mul = 1;
        for (auto &n : nums)
        {
            if (n != 0)
            {
                mul *= n;
            }
            else if (has_zero)
            {
                mul = 0;
                break;
            }
            else
            {
                has_zero = true;
            }
        }
        if (mul == 0)
        {
            for (auto &n : nums)
            {
                n = 0;
            }
            return nums;
        }
        else if (has_zero)
        {
            for (auto &n : nums)
            {
                if (n != 0)
                {
                    n = 0;
                }
                else
                {
                    n = mul;
                }
            }
            return nums;
        }
        for (auto &n : nums)
        {
            n = mul / n;
        }
        return nums;
    }
};
// @lc code=end
