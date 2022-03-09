/*
 * @lc app=leetcode id=1437 lang=cpp
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return true;
        }
        auto pos = find(nums.begin(), nums.end(), 1);
        while (true)
        {
            auto next_pos = find(pos + 1, nums.end(), 1);
            if (next_pos == nums.end())
            {
                break;
            }
            else if (next_pos - pos <= k)
            {
                return false;
            }
            pos = next_pos;
        }
        return true;
    }
};
// @lc code=end
