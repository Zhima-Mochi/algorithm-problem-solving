/*
 * @lc app=leetcode id=1922 lang=cpp
 *
 * [1922] Count Good Numbers
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(log(n)), s:O(1)
int mod = 1000000007;
class Solution
{
public:
    int countGoodNumbers(long long n)
    {
        long long res = 1;
        vector<long long> memo{5, 20};
        for (int i = 0; i != 64; ++i)
        {
            memo.push_back(memo.back() * memo.back() % mod);
        }
        int cur = 0;
        while (n)
        {
            if (n % 2)
            {
                res *= memo[cur];
                res %= mod;
            }
            n /= 2;
            cur++;
        }
        return res;
    }
};
// @lc code=end
