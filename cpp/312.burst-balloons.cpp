/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        int w = nums.size();
        int **dp = new int *[w + 2];
        for (int i = 0; i != w + 2; ++i)
        {
            dp[i] = new int[w + 2];
            for (int j = 0; j != w + 2; ++j)
            {
                dp[i][j] = 0;
            }
        }
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for (int i = w - 1; i != -1; --i)
        {
            for (int j = i + 2; j != w + 2; ++j)
            {
                for (int l = i + 1; l != j; ++l)
                {
                    int val = nums[i] * nums[l] * nums[j];
                    dp[i][j] = max(dp[i][j], val + dp[i][l] + dp[l][j]);
                }
            }
        }
        return dp[0][w + 1];
    }
};
// @lc code=end
//[3,0,9,4,1,2,3,44,21,98,21,34,0,4,5,2,1,88]
//[4,1,2,3,44,21,98,21]
//[3,4,7,9,7]