/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int pos = 0;
        vector<int> res;
        res.reserve(2 * n);
        while (pos < n)
        {
            res.push_back(nums[pos]);
            res.push_back(nums[n + pos++]);
        }
        return res;
    }
};
// @lc code=end
