/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;
    }
};
// @lc code=end
