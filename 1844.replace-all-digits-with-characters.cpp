/*
 * @lc app=leetcode id=1844 lang=cpp
 *
 * [1844] Replace All Digits with Characters
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string replaceDigits(string s)
    {
        char prev;
        for (auto &c : s)
        {
            if (isdigit(c))
            {
                c = c - '0' + prev;
            }
            else
            {
                prev = c;
            }
        }
        return s;
    }
};
// @lc code=end
