/*
 * @lc app=leetcode id=831 lang=cpp
 *
 * [831] Masking Personal Information
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string maskPII(string s)
    {
        string res;
        int width = s.size();
        if (isalpha(s[0]))
        {
            res.push_back(tolower(s[0]));
            int at_pos = s.find('@');
            if (at_pos != 1)
            {
                res.append(string(5, '*'));
                res.push_back(tolower(s[at_pos - 1]));
            }
            res.push_back('@');
            for (int i = at_pos + 1; i != width; ++i)
            {
                res.push_back(tolower(s[i]));
            }
        }
        else
        {
            for (int i = width - 1; i != -1; --i)
            {
                if (isdigit(s[i]))
                {
                    if (res.size() < 4)
                    {
                        res.push_back(s[i]);
                    }
                    else if (res.size() < 8)
                    {
                        if (res.size() == 4)
                        {
                            res.push_back('-');
                        }
                        res.push_back('*');
                    }
                    else if (res.size() < 12)
                    {
                        if (res.size() == 8)
                        {
                            res.push_back('-');
                        }
                        res.push_back('*');
                    }
                    else
                    {
                        if (res.size() == 12)
                        {
                            res.push_back('-');
                        }
                        res.push_back('*');
                    }
                }
            }
            if (res.size() > 12)
            {
                res.push_back('+');
            }
            reverse(res.begin(), res.end());
        }
        return res;
    }
};
// @lc code=end
