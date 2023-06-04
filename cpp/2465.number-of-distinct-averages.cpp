/*
 * @lc app=leetcode id=2465 lang=cpp
 *
 * [2465] Number of Distinct Averages
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(n*log(n)), s:O(n)
class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        vector<bool> exist(201);
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            exist[nums[left] + nums[right]] = true;
            ++left;
            --right;
        }
        int res = 0;
        for (int i = 0; i != 201; ++i)
        {
            if (exist[i])
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
