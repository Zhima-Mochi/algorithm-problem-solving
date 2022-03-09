/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        int count = 0;
        bool next_right = false;
        while (left < right)
        {
            if (s[left] == s[right])
            {
                ++left;
                --right;
            }
            else
            {
                if (next_right)
                {
                    --right;
                }
                else if (count == 1)
                {
                    return false;
                }
                else
                {
                    ++count;
                }
                if (left + 1 == right)
                {
                    return true;
                }
                else if (s[left + 1] == s[right] && s[left] == s[right - 1])
                {
                    ++left;
                    next_right = true;
                }
                else if (s[left + 1] == s[right])
                {
                    ++left;
                }
                else if (s[left] == s[right - 1])
                {
                    --right;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
