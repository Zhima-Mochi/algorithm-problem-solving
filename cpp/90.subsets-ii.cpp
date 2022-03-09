/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    static void binary_search(vector<int> &nums, int &left, int value)
    {
        auto right = nums.size();
        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            if (nums[mid] == value)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        auto len = nums.size();
        int i = 0;
        while (i < len)
        {
            auto res_len = res.size();
            auto next_i = i;
            binary_search(nums, next_i, nums[i]);
            for (int ind = 0; ind != res_len; ++ind)
            {
                res.push_back(res[ind]);
                res.back().push_back(nums[i]);
                for (int j = i + 1; j != next_i; ++j)
                {
                    res.push_back(res.back());
                    res.back().push_back(nums[i]);
                }
            }
            i = next_i;
        }
        return res;
    }
};
// @lc code=end
