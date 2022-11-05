/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        vector<pair<char, bool>> stk;
        stk.push_back({'&', true});
        auto cur = 0;
        int w = expression.size();
        while (cur < w)
        {
            auto c = expression[cur];
            if (c == ',')
            {
                ++cur;
                continue;
            }
            if (c == 't' || c == 'f')
            {
                bool val = true ? c == 't' : false;
                switch (stk.back().first)
                {
                case '&':
                    stk.back().second &= val;
                    break;
                case '|':
                    stk.back().second |= val;
                    break;
                case '!':
                    stk.back().second = val;
                    break;
                default:
                    break;
                }
            }
            if (c == '&')
            {
                stk.push_back({'&', true});
                ++cur;
            }
            else if (c == '|')
            {
                stk.push_back({'|', false});
                ++cur;
            }
            else if (c == '!')
            {
                stk.push_back({'!', true});
                ++cur;
            }
            else if (c == ')')
            {
                bool val = stk.back().second;
                if (stk.back().first == '!')
                {
                    val = !val;
                }
                stk.pop_back();
                switch (stk.back().first)
                {
                case '&':
                    stk.back().second &= val;
                    break;
                case '|':
                    stk.back().second |= val;
                    break;
                case '!':
                    stk.back().second = val;
                    break;
                }
            }
            ++cur;
        }
        return stk.back().second;
    }
};
// @lc code=end
