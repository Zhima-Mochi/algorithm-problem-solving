/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string solveEquation(string equation)
    {
        int width = equation.size();
        int x_coef = 0;
        int c_coef = 0;
        int pos = 0;
        int val = 0;
        int sign = 1;
        int side_sign = 1;
        for (int i = 0; i != width; ++i)
        {
            if (equation[i] == 'x')
            {
                if (i == 0 || !isdigit(equation[i - 1]))
                {
                    x_coef += side_sign * sign;
                }
                else
                {
                    x_coef += val * side_sign * sign;
                    val = 0;
                }
            }
            else if (equation[i] == '+')
            {
                c_coef += side_sign * sign * val;
                sign = 1;
                val = 0;
            }
            else if (equation[i] == '-')
            {
                c_coef += side_sign * sign * val;
                sign = -1;
                val = 0;
            }
            else if (equation[i] == '=')
            {
                c_coef += side_sign * sign * val;
                sign = 1;
                side_sign = -1;
                val = 0;
            }
            else
            {
                val *= 10;
                val += equation[i] - '0';
            }
        }
        c_coef += side_sign * sign * val;
        if (x_coef == 0)
        {
            if (c_coef != 0)
            {
                return "No solution";
            }
            else
            {
                return "Infinite solutions";
            }
        }
        else
        {
            return "x=" + to_string(-c_coef / x_coef);
        }
    }
};
// @lc code=end
