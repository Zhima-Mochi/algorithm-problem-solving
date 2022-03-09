/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int len = s.size();
        s.push_back(' ');
        string res;
        for (int i = len - 1; i != -1; --i)
        {
            if (s[i] == ' ' && s[i + 1] != ' ')
            {
                res.append(s.substr(i + 1, s.find(' ', i + 1) - (i + 1)));
                res.push_back(' ');
            }
        }
        if (s[0] != ' ')
        {
            res.append(s.substr(0, s.find(' ', 0)));
        }
        else if (!res.empty())
        {
            res.pop_back();
        }
        return res;
    }
};
// @lc code=end
