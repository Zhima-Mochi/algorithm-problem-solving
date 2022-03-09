/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        auto width = nums.size();
        if (width <= 100000)
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i != width - 1; ++i)
            {
                if (nums[i + 1] == nums[i])
                {
                    return true;
                }
            }
            return false;
        }
        //Not necessary in this problem.
        else
        {
            unordered_map<int, int> mp;
            for (auto &n : nums)
            {
                if (++mp[n] == 2)
                {
                    return true;
                }
            }
            return false;
        }
        return true;
    }
};
// @lc code=end
