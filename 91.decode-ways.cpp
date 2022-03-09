/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.front() == '0')
        {
            return 0;
        }
        auto len = s.size();
        if (len == 1)
        {
            return 1;
        }
        auto count = 1;
        auto prev_count = 1;
        for (int i = 1; i != len; ++i)
        {
            auto next_prev_count = count;
            if (s[i - 1] == '0')
            {
                if (s[i] == '0')
                {
                    return 0;
                }
            }
            else if (stoi(s.substr(i - 1, 2)) <= 26)
            {
                if (s[i] == '0')
                {
                    count = prev_count;
                }
                else
                {
                    count += prev_count;
                }
            }
            else if (s[i] == '0')
            {
                return 0;
            }
            prev_count = next_prev_count;
        }
        return count;
    }
};
// @lc code=end
//"12"\n"120"\n"1201"\n"12012"\n"11"\n"112"\n"1123"\n