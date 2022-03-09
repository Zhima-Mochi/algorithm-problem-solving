/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (!num)
        {
            return "0";
        }
        bool is_negative = num < 0;
        if (is_negative)
            num *= -1;
        string res;
        while (num)
        {
            res.push_back('0' + num % 7);
            num /= 7;
        }
        if (is_negative)
        {
            res.push_back('-');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
