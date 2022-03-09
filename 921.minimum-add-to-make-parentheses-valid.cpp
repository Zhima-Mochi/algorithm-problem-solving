/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int left = 0, right = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                ++left;
            }
            else if (left)
            {
                --left;
            }
            else
            {
                ++right;
            }
        }
        return left + right;
    }
};
// @lc code=end
