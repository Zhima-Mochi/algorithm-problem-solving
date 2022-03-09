/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{

public:
    string longestNiceSubstring(string s)
    {
        int width = s.size();
        return longestNiceSubstring(s, 0, width - 1);
    }
    string longestNiceSubstring(string &s, int left, int right)
    {
        if (left > right)
        {
            return "";
        }
        string count(26, 0);
        for (int i = left; i <= right; ++i)
        {
            if (islower(s[i]))
            {
                count[s[i] - 'a'] |= 1;
            }
            else
            {
                count[s[i] - 'A'] |= 2;
            }
        }
        for (int i = left; i <= right; ++i)
        {
            if (count[tolower(s[i])-'a'] != 3)
            {
                auto left_s = longestNiceSubstring(s, left, i - 1);
                auto right_s = longestNiceSubstring(s, i + 1, right);
                return left_s.size() >= right_s.size() ? left_s : right_s;
            }
        }
        return s.substr(left, right - left + 1);
    }
};
// @lc code=end
