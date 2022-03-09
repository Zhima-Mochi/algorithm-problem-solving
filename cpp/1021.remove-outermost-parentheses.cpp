/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int count = 0;
        string res;
        for (auto c : s)
        {
            if (c == '(')
            {
                ++count;
                if (count != 1)
                {
                    res.push_back(c);
                }
            }
            else
            {
                --count;
                if (count != 0)
                {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};
// @lc code=end
