/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n) s:O(1)
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long cont = 0;
        long long res = 0;
        for (auto n : nums)
        {
            if (n != 0)
            {
                cont = 0;
            }
            else
            {
                cont += 1;
                res += cont;
            }
        }
        return res;
    }
};
// @lc code=end
