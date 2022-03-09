/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char res = 0;
        for (char c : s)
        {
            res ^= c;
        }
        for (char c : t)
        {
            res ^= c;
        }
        return res;
    }
};
// @lc code=end
