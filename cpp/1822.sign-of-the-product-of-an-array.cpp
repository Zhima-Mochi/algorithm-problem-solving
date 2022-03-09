/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int res = 1;
        for (auto n : nums)
        {
            if (n < 0)
            {
                res *= -1;
            }
            else if (n == 0)
            {
                return 0;
            }
        }
        return res;
    }
};
// @lc code=end
