/*
 * @lc app=leetcode id=2731 lang=cpp
 *
 * [2731] Movement of Robots
 */
#include <vector>
#include <string>
#include <climits>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(log(n))
class Solution
{
public:
    int MOD = 1000000007;
    int sumDistance(vector<int> &nums, string s, int d)
    {
        int n = nums.size();
        for (int i = 0; i != n; ++i)
        {
            if (s[i] == 'L')
            {
                nums[i] -= d;
            }
            else
            {
                nums[i] += d;
            }
        }
        sort(nums.begin(), nums.end());
        long long res = 0;
        for (int i = 0; i != n - 1; ++i)
        {
            res += (1LL * nums[i + 1] - nums[i]) % MOD * (n - 1 - i) % MOD * (i + 1) % MOD;
            res %= MOD;
        }
        return res;
    }
};
// @lc code=end
