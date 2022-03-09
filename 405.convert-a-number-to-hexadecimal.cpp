/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        bool is_negative = num < 0;
        auto count = 8;
        string pre_res;
        while (count && (num != 0 && num != -1))
        {
            auto n = num & 15;
            if (n <= 9)
            {
                pre_res.push_back('0' + n);
            }
            else
            {
                pre_res.push_back('a' + n - 10);
            }
            num >>= 4;
            --count;
        }
        reverse(pre_res.begin(), pre_res.end());
        return is_negative ? string(count, 'f') + pre_res : pre_res;
    }
};
// @lc code=end
