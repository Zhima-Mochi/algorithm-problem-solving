/*
 * @lc app=leetcode id=2681 lang=cpp
 *
 * [2681] Power of Heroes
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(log(n))
int mod = 1000000007;
class Solution
{
public:
    int sumOfPower(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        long long prev_total_min = 0;
        long long res = 0;
        int w = nums.size();
        for (int i = 0; i != w; ++i)
        {
            res += prev_total_min * (1LL * nums[i] * nums[i] % mod);
            res += (1LL * nums[i] * nums[i] % mod * nums[i] % mod);
            res %= mod;
            prev_total_min = 2 * prev_total_min + nums[i];
            prev_total_min %= mod;
        }

        return res;
    }
};
// @lc code=end
