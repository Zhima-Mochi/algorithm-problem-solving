/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // for (auto &n : nums)
        // {
        //     n *= n;
        // }
        // sort(nums.begin(), nums.end());
        // return nums;
        vector<int> res;
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left < right)
        {
            if (abs(nums[left]) < nums[right])
            {
                res.push_back(nums[right] * nums[right]);
                --right;
            }
            else
            {
                res.push_back(nums[left] * nums[left]);
                ++left;
            }
        }
        res.push_back(nums[left]*nums[left]);
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
