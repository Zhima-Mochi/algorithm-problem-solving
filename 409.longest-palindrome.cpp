/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int len = s.size();
        unordered_map<char, short> ump;
        int count = 0;
        for (auto c : s)
        {
            if (++ump[c] % 2 == 0)
            {
                count += 2;
            }
        }
        if (count < len)
        {
            return count + 1;
        }
        else
        {
            return count;
        }
        
    }
};
// @lc code=end
