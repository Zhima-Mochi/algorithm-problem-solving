/*
 * @lc app=leetcode id=2110 lang=cpp
 *
 * [2110] Number of Smooth Descent Periods of a Stock
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        int n = prices.size();
        long long res = n;
        for (int i = n - 1; i != 0; --i)
        {
            prices[i] -= prices[i - 1];
        }
        int prev = 0;
        for (int i = 0; i != n; ++i)
        {
            if (prices[i] != -1)
            {
                prev = i + 1;
            }
            else
            {
                res += i - prev + 1;
            }
        }
        return res;
    }
};
// @lc code=end
