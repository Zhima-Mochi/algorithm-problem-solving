/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    vector<string> unit_digit = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> ten_digit = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> two_digit = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

public:
    string numberToWords(int num)
    {
        string res;
        if (num == 0)
        {
            return "Zero";
        }
        else if (num < 100)
        {
            if (num >= 20)
            {
                res = ten_digit[num / 10 - 2] + " " + (num % 10 ? unit_digit[num % 10] + " " : "");
                res.pop_back();
                return res;
            }
            else if (num >= 10)
            {
                return two_digit[num - 10];
            }
            else
            {
                return unit_digit[num];
            }
        }
        int billion_num = num / 1000000000;
        num %= 1000000000;
        int million_num = num / 1000000;
        num %= 1000000;
        int thousand_num = num / 1000;
        num %= 1000;
        int hundred_num = num / 100;
        num %= 100;
        res = (billion_num == 0 ? "" : numberToWords(billion_num) + " Billion ") + (million_num == 0 ? "" : numberToWords(million_num) + " Million ") +
              (thousand_num == 0 ? "" : numberToWords(thousand_num) + " Thousand ") + (hundred_num == 0 ? "" : numberToWords(hundred_num) + " Hundred ") +
              (num == 0 ? "" : numberToWords(num) + " ");
        res.pop_back();
        return res;
    }
};
// @lc code=end
