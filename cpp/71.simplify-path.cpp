/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        string res = {'/'};
        path.push_back('/');
        for (auto &c : path)
        {
            string temp;
            if (c == '/')
            {
                if (res.back() != '/' && res.back() != '.')
                {
                    res.push_back('/');
                    continue;
                }
                while (res.back() != '/')
                {
                    temp.push_back(res.back());
                    res.pop_back();
                }
                if (temp == "" || temp == ".")
                {
                    continue;
                }
                else if (temp != "..")
                {
                    while(!temp.empty()){
                        res.push_back(temp.back());
                        temp.pop_back();
                    }
                    res.push_back('/');
                }
                else
                {
                    if (res.size() == 1)
                    {
                        continue;
                    }
                    res.pop_back();
                    while (res.back() != '/')
                    {
                        res.pop_back();
                    }
                }
            }
            else
            {
                res.push_back(c);
            }
        }
        if (res.size() > 1)
        {
            res.pop_back();
        }
        return res;
    }
};
// @lc code=end
