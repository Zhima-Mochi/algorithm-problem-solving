/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int len = nums.size();
        int res = 0;
        for (int i = 0; i != len; ++i)
        {
            if (nums[i] >= 0)
            {
                nums[i] *= -1;
                nums[i] -= 1;
                int pos = -nums[i] - 1;
                int count = 1;
                while (nums[pos] >= 0)
                {
                    ++count;
                    nums[pos] *= -1;
                    nums[pos] -= 1;
                    pos = -nums[pos] - 1;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
// @lc code=end
