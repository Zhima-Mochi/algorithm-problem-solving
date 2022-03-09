/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    void generator(vector<string> &res, string paren_word, int left_num, int close_num)
    {
        if (left_num == 0 && close_num == 0)
        {
            res.push_back(paren_word);
            return;
        }
        if (left_num > 0)
        {
            generator(res, paren_word + '(', left_num - 1, close_num + 1);
        }
        if (close_num > 0)
        {
            generator(res, paren_word + ')', left_num, close_num - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        generator(res,"",n,0);
        return res;
    }
};
// @lc code=end
