/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string toLowerCase(string s)
    {
        for (auto &c : s)
        {
            if (isupper(c))
            {
                c = tolower(c);
            }
        }
        return s;
    }
};
// @lc code=end
