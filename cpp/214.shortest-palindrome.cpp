/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */
#include <string>
using namespace std;
// @lc code=start
// t:O(len(s)), s:O(1)
class Solution
{
    int base = 29, mod = 1000000007;

public:
    string shortestPalindrome(string s)
    {
        int w = s.size();
        if (w <= 1)
        {
            return s;
        }
        long long left = 0, right = 0, mp = 1;
        int idx = -1;
        for (int i = 0; i != w; ++i)
        {
            left = (left * base + (s[i] - 'a' + 1)) % mod;
            right = (right + mp * (s[i] - 'a' + 1)) % mod;
            if (left == right)
            {
                idx = i;
            }
            mp = mp * base % mod;
        }
        string res = s.substr(idx + 1, w - idx - 1);
        reverse(res.begin(), res.end());
        res += s;
        return res;
    }
};
// @lc code=end
