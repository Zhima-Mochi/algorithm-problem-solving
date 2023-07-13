/*
 * @lc app=leetcode id=1012 lang=cpp
 *
 * [1012] Numbers With Repeated Digits
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int Pi(int a, int b)
    {
        int res = 1;
        for (int i = 0; i != a; ++i)
        {
            res *= b--;
        }
        return res;
    }
    int f(int mask, const string &s, int pos, bool same)
    {
        if (pos == s.size())
        {
            return 1;
        }
        int t = same ? s[pos] - '0' : 9;
        int res = 0;
        int c = __builtin_popcount(mask) + 1;
        for (int k = 0; k <= t; k++)
        {
            if (mask & (1 << k))
            {
                continue;
            }
            if (same && k == t)
            {
                res += f(mask | (1 << t), s, pos + 1, true);
            }
            else if (mask == 0 && k == 0)
            {
                res += f(0, s, pos + 1, false);
            }
            else
            {
                res += Pi(s.size() - 1 - pos, 10 - c);
            }
        }
        return res;
    }
    int numDupDigitsAtMostN(int n)
    {
        string s = to_string(n);
        return n + 1 - f(0, s, 0, true);
    }
};
// @lc code=end
