/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string makeFancyString(string s)
    {
        int width = s.size();
        if (width < 2)
        {
            return s;
        }
        string res = s.substr(0, 2);
        for (int i = 2; i != width; ++i)
        {
            if (s[i] != res.back() || s[i] != res[res.size() - 2])
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
// @lc code=end
