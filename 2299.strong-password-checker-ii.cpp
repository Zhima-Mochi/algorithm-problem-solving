/*
 * @lc app=leetcode id=2299 lang=cpp
 *
 * [2299] Strong Password Checker II
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    string s = "!@#$%^&*()-+";
public:
    bool strongPasswordCheckerII(string password)
    {
        if (password.size() < 8)
        {
            return false;
        }
        int check = 0;
        char prev = 0;
        for (auto c : password)
        {
            if (c == prev)
            {
                return false;
            }
            if (islower(c))
            {
                check |= 1;
            }
            else if (isupper(c))
            {
                check |= 1 << 1;
            }
            else if (isdigit(c))
            {
                check |= 1 << 2;
            }
            else if (s.find(c) != -1)
            {
                check |= 1 << 3;
            }
            prev = c;
        }
        return check == 15;
    }
};
// @lc code=end
