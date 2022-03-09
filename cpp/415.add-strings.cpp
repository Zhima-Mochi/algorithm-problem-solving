/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res;
        int rest = 0;
        while (!num1.empty() && !num2.empty())
        {
            auto sum_v = (num1.back() - '0' + num2.back() - '0') + rest;
            res.push_back('0' + (sum_v % 10));
            rest = sum_v / 10;
            num1.pop_back();
            num2.pop_back();
        }

        while (!num1.empty())
        {
            auto sum_v = (num1.back() - '0') + rest;
            res.push_back('0' + (sum_v % 10));
            rest = sum_v / 10;
            num1.pop_back();
        }
        while (!num2.empty())
        {
            auto sum_v = (num2.back() - '0') + rest;
            res.push_back('0' + (sum_v % 10));
            rest = sum_v / 10;
            num2.pop_back();
        }
        if(rest){
            res.push_back('0'+rest);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
