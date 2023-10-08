/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */
#include <vector>
#include <cstring>
using namespace std;
// @lc code=start
// t:O(n1*n2), s:O(n1*n2)
class Solution
{
public:
    int memo[501][501];
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        memset(memo, -10000000, sizeof(memo));
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 0; i != n1; ++i)
        {
            for (int j = 0; j != n2; ++j)
            {
                memo[i + 1][j + 1] = max({nums1[i] * nums2[j], memo[i + 1][j], memo[i][j + 1], memo[i][j] + nums1[i] * nums2[j]});
            }
        }
        return memo[n1][n2];
    }
};
// @lc code=end
