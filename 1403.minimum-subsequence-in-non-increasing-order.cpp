/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        int sum_val = accumulate(nums.begin(), nums.end(), 0);
        vector<int> count_sort(101);
        for (auto n : nums)
        {
            ++count_sort[n];
        }
        int count = 0;
        vector<int> res;
        for (int i = 100; i != 0; --i)
        {
            while (count_sort[i] && count <= sum_val / 2)
            {
                res.push_back(i);
                count += i;
                --count_sort[i];
            }
            if (count > sum_val / 2)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
