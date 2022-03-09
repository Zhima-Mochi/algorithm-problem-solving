/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <string>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int myAtoi(string &s)
    {
        int w = s.size();
        long long res = 0;
        long long sign = 1;
        int idx = 0;
        for (auto c : s)
        {
            if (c == '+')
            {
                ++idx;
                break;
            }
            else if (c == '-')
            {
                sign = -1;
                ++idx;
                break;
            }
            else if (isdigit(c))
            {
                break;
            }
            else if (!isblank(c))
            {
                return 0;
            }
            ++idx;
        }
        for (int i = idx; i != w && isdigit(s[i]); ++i)
        {
            res *= 10;
            res += s[i] - '0';
            if (res * sign > INT32_MAX)
            {
                return INT32_MAX;
            }
            else if (res * sign < INT32_MIN)
            {
                return INT32_MIN;
            }
        }
        return res * sign;
    }
};
// @lc code=end
