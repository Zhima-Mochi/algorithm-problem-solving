/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removePalindromeSub(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] == s[right])
            {
                ++left, --right;
            }
            else
            {
                return 2;
            }
        }
        return 1;
    }
};
// @lc code=end
