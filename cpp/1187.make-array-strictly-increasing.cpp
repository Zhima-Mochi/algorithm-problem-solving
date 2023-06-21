/*
 * @lc app=leetcode id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// @lc code=start
// t:O(n^2) s:O(n^2)
class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        auto iter = unique(arr2.begin(), arr2.end());
        arr2.erase(iter, arr2.end());
        int w1 = arr1.size(), w2 = arr2.size();
        vector<vector<int>> dp(w1 + 1, vector<int>(min(w1, w2) + 1, INT_MAX));
        dp[0][0] = -1;
        for (int i = 1; i <= w1; i++)
        {
            for (int j = 0; j <= min(i, w2); j++)
            {
                if (arr1[i - 1] > dp[i - 1][j])
                {
                    dp[i][j] = arr1[i - 1];
                }
                if (j > 0 && dp[i - 1][j - 1] != INT_MAX)
                {
                    auto it = upper_bound(arr2.begin() + j - 1, arr2.end(), dp[i - 1][j - 1]);
                    if (it != arr2.end())
                    {
                        dp[i][j] = min(dp[i][j], *it);
                    }
                }
                if (i == w1 && dp[i][j] != INT_MAX)
                {
                    return j;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
