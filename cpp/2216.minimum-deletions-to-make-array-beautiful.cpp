/*
 * @lc app=leetcode id=2216 lang=cpp
 *
 * [2216] Minimum Deletions to Make Array Beautiful
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int n = nums.size();
        int idx = 0;
        int res = 0;
        for (int i = 0; i != n; ++i)
        {
            if (idx % 2 && nums[i - 1] == nums[i])
            {
                res += 1;
            }
            else
            {
                idx += 1;
            }
        }
        return idx % 2 == 0 ? res : res + 1;
    }
};
// @lc code=end
