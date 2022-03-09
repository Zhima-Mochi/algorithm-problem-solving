/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int base = 20000;

public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        vector<int> prev_diff_max_count(40001);
        int res = 1;
        for (auto n : arr)
        {
            prev_diff_max_count[n + base] = prev_diff_max_count[n - difference + base] + 1;
            res = max(res, prev_diff_max_count[n + base]);
        }
        return res;
    }
};
// @lc code=end
