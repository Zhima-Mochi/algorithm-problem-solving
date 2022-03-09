/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkValidString(string s)
    {
        int muteki_symbol = 0;
        int trans_to_left_symbol = 0;
        int rest_min_left = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                ++rest_min_left;
            }
            else if (c == ')')
            {
                if (rest_min_left > 0)
                {
                    --rest_min_left;
                }
                else if (muteki_symbol > 0)
                {
                    --muteki_symbol;
                }
                else if (trans_to_left_symbol > 0)
                {
                    --trans_to_left_symbol;
                    ++muteki_symbol;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (rest_min_left > 0)
                {
                    --rest_min_left;
                    ++trans_to_left_symbol;
                }
                else
                {
                    ++muteki_symbol;
                }
            }
        }
        return rest_min_left == 0;
    }
};

// @lc code=end
