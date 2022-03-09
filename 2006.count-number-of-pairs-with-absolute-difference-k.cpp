/*
 * @lc app=leetcode id=2006 lang=cpp
 *
 * [2006] Count Number of Pairs With Absolute Difference K
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        vector<int> record(201);
        int res = 0;
        for (auto n : nums)
        {
            if (n >= k)
            {
                res += record[n - k];
            }
            if (n + k <= 200)
            {
                res += record[n + k];
            }
            ++record[n];
        }
        return res;
    }
};
// @lc code=end
