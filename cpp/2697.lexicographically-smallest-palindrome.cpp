/*
 * @lc app=leetcode id=2697 lang=cpp
 *
 * [2697] Lexicographically Smallest Palindrome
 */
#include <string>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        int n = s.size();
        for (int i = 0; i != n / 2; ++i)
        {
            s[i] = s[n - 1 - i] = min(s[i], s[n - 1 - i]);
        }
        return s;
    }
};
// @lc code=end
