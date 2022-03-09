/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string interpret(string command)
    {
        string res;
        char prev_char;
        bool inside = false;
        for (auto c : command)
        {
            if (isalpha(c) && !inside)
            {
                res.push_back(c);
            }
            else if (c == '(')
            {
                inside = true;
            }
            else if (c == ')')
            {
                if (prev_char == '(')
                {
                    res.push_back('o');
                }
                else
                {
                    res.append("al");
                }
                inside = false;
            }
            prev_char = c;
        }
        return res;
    }
};
// @lc code=end
