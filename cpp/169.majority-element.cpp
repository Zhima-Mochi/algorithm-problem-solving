/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1;
        int res = nums[0];
        auto len = nums.size();
        for (size_t i = 1; i != len; i++)
        {
            if (count == 0)
            {
                res = nums[i];
                count++;
            }
            else if (res == nums[i])
            {
                count++;
            }else{
                count--;
            }
        }
        return res;
    }
};
// @lc code=end
