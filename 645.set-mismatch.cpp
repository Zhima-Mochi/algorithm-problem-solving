/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int repeat;
        for (auto &n : nums)
        {
            if (nums[abs(n) - 1] < 0)
            {
                repeat = abs(n);
            }
            else
            {
                nums[abs(n) - 1] *= -1;
            }
        }
        int len = nums.size();
        for (int i = 0; i != len; ++i)
        {
            if (nums[i] > 0)
            {
                return vector<int>{repeat, i + 1};
            }
        }
        return vector<int>();
    }
};
// @lc code=end
