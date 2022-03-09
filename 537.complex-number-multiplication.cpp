/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        string res;
        short num1_real = stoi(num1.substr(0, num1.find('+')));
        short num1_img = stoi(num1.substr(num1.find('+') + 1, num1.size() - num1.find('+') - 2));
        short num2_real = stoi(num2.substr(0, num2.find('+')));
        short num2_img = stoi(num2.substr(num2.find('+') + 1, num2.size() - num2.find('+') - 2));
        res.append(to_string(num1_real * num2_real - num1_img * num2_img));
        res.push_back('+');
        res.append(to_string(num1_real * num2_img + num1_img * num2_real));
        res.push_back('i');
        return res;
    }
};
// @lc code=end
