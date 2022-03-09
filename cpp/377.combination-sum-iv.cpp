/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned> sumVec(target + 1);
        sumVec[0] = 1;
        int len = nums.size();
        for (int i = 1; i != target + 1; ++i)
        {
            for (int j = 0; j != len; ++j)
            {
                if (nums[j] <= i)
                {
                    sumVec[i] += sumVec[i - nums[j]];
                }
            }
        }
        return sumVec.back();
    }
};
// @lc code=end
