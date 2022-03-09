/*
 * @lc app=leetcode id=1576 lang=cpp
 *
 * [1576] Replace All ?'s to Avoid Consecutive Repeating Characters
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string modifyString(string s)
    {
        int width = s.size();
        if (width == 1)
        {
            return s == "?" ? "a" : s;
        }
        if (s[0] == '?')
        {
            s[0] = s[1] == '?' ? 'a' : (s[1] + 1 - 'a') % 26 + 'a';
        }
        for (int i = 1; i < width - 1; ++i)
        {
            if (s[i] == '?')
            {
                s[i] = (s[i - 1] + 1 - 'a') % 26 + 'a';
            }
            if (s[i] == s[i + 1])
            {
                s[i] = (s[i + 1] + 1 - 'a') % 26 + 'a';
            }
        }
        if (s[width - 1] == '?')
        {
            s[width - 1] = (s[width - 2] + 1 - 'a') % 26 + 'a';
        }
        return s;
    }
};
// @lc code=end
