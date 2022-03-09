/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */
#include <string>
#include <regex>
using namespace std;
// @lc code=start
class Solution
{
public:
    string fractionAddition(string expression)
    {
        int width = expression.size();
        int pos = expression.find('/');
        int numerator = stoi(expression.substr(0, pos));
        int next_pos = expression.find_first_of("+-", pos + 2);
        int denominator = pos == -1 ? stoi(expression.substr(pos + 1)) : stoi(expression.substr(pos + 1, next_pos - pos - 1));
        pos = next_pos;
        while (pos != -1)
        {
            next_pos = expression.find('/', pos);
            int next_n = stoi(expression.substr(pos, next_pos - pos));
            pos = next_pos;
            next_pos = expression.find_first_of("+-", pos + 2);
            int next_d = pos == -1 ? stoi(expression.substr(pos + 1)) : stoi(expression.substr(pos + 1, next_pos - pos - 1));
            pos = next_pos;
            numerator = numerator * next_d + denominator * next_n;
            denominator *= next_d;
            red_of_frac(numerator, denominator);
        }
        return to_string(numerator) + '/' + to_string(denominator);
    }
    void red_of_frac(int &n, int &d)
    {
        bool is_negative = (n < 0) ^ (d < 0);
        int gcd_val = gcd(abs(n), abs(d));
        n = abs(n) / gcd_val * (is_negative ? -1 : 1);
        d = abs(d) / gcd_val;
    }
    int gcd(int n, int m)
    {
        if (n < m)
        {
            swap(n, m);
        }
        while (m != 0)
        {
            n %= m;
            swap(n, m);
        }
        return n;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     string fractionAddition(string expression)
//     {
//         regex fraction_regex("([+-]?[[:digit:]]+)/([+-]?[[:digit:]]+)");
//         auto words_begin = sregex_iterator(expression.begin(), expression.end(), fraction_regex);
//         auto words_end = sregex_iterator();

//         int numerator = 0;
//         int denominator = 1;
//         for (auto i = words_begin; i != words_end; ++i)
//         {
//             auto match = *i;
//             int next_n = stoi(match[1].str());
//             int next_d = stoi(match[2].str());
//             numerator = numerator * next_d + denominator * next_n;
//             denominator *= next_d;
//             red_of_frac(numerator, denominator);
//         }
//         return to_string(numerator) + '/' + to_string(denominator);
//     }
//     void red_of_frac(int &n, int &d)
//     {
//         bool is_negative = (n < 0) ^ (d < 0);
//         int gcd_val = gcd(abs(n), abs(d));
//         n = abs(n) / gcd_val * (is_negative ? -1 : 1);
//         d = abs(d) / gcd_val;
//     }
//     int gcd(int n, int m)
//     {
//         if (n < m)
//         {
//             swap(n, m);
//         }
//         while (m != 0)
//         {
//             n %= m;
//             swap(n, m);
//         }
//         return n;
//     }
// };