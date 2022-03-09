/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */
#include <string>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 == str2 + str1)
        {
            return str1.substr(0, gcd(str1.size(), str2.size()));
        }
        else
        {
            return "";
        }
    }
};
// @lc code=end
