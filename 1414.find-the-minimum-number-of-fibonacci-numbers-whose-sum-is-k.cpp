/*
 * @lc app=leetcode id=1414 lang=cpp
 *
 * [1414] Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(log(N)), s:O(log(N))
class Solution
{
public:
    int findMinFibonacciNumbers(int k)
    {
        vector<int> dp = {1};
        vector<int> f = {0, 1, 1};
        int pt = 0;
        while (dp.back() < k)
        {
            swap(f[pt], f.back());
            pt = (pt + 1) % 2;
            f.back() = 0;
            for (int i = 0; i != 2; ++i)
            {
                f.back() += f[i];
            }
            dp.push_back(f.back());
        }
        int res = 0;
        for (int i = dp.size() - 1; i != -1; --i)
        {
            if (dp[i] <= k)
            {
                k -= dp[i];
                ++res;
            }
            if (k == 0)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
