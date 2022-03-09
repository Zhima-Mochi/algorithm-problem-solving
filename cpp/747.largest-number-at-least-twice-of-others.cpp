/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int res = 0;
        bool goal = true;
        int len = nums.size();
        for (int i = 1; i != len; ++i)
        {
            if (nums[i] > nums[res])
            {
                if (nums[i] >= 2 * nums[res])
                {
                    goal = true;
                }
                else
                {
                    goal = false;
                }
                res = i;
            }
            else if (nums[i] > nums[res] / 2)
            {
                goal = false;
            }
        }
        return goal ? res : -1;
    }
};
// @lc code=end
