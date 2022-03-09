/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int mod = 1337;

public:
    int superPow(int a, vector<int> &b)
    {
        a %= mod;
        int width = b.size();
        vector<int> pow_val = {1, a};
        for (int i = 2; i != 10; ++i)
        {
            pow_val.push_back(pow_val.back() * a % mod);
        }
        int res = pow_val[b[0]];
        for (auto i = 1; i != width; ++i)
        {
            res *= res;
            res %= mod;
            int residule = res;
            res *= res;
            res %= mod;
            res *= res;
            res %= mod;
            res *= residule;
            res %= mod;
            res *= pow_val[b[i]];
            res %= mod;
        }
        return res;
    }
};
// @lc code=end
