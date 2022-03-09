/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string defangIPaddr(string address)
    {
        string res;
        for (auto c : address)
        {
            if (c != '.')
            {
                res.push_back(c);
            }
            else
            {
                res.append("[.]");
            }
        }
        return res;
    }
};
// @lc code=end
