/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(N*k), s:O(N)
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int w = arr.size();
        vector<int> dp(w + 1);
        for (int i = 0; i != w; ++i)
        {
            int max_val = 0;
            for (int j = i; j >= 0 && j > i - k; --j)
            {
                max_val = max(max_val, arr[j]);
                dp[i + 1] = max(dp[i + 1], dp[j] + max_val * (i - j + 1));
            }
        }
        return dp[w];
    }
};
// @lc code=end
