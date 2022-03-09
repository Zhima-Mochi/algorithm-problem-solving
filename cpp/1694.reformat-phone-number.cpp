/*
 * @lc app=leetcode id=1694 lang=cpp
 *
 * [1694] Reformat Phone Number
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reformatNumber(string number)
    {
        string res = "";
        int count = 0;
        for (auto c : number)
        {
            if (isdigit(c))
            {
                ++count;
                res.push_back(c);
                if (count == 3)
                {
                    res.push_back('-');
                    count = 0;
                }
            }
        }
        if (res.size() > 1 && count == 1)
        {
            swap(res[res.size() - 2], res[res.size() - 3]);
        }
        else if (count == 0)
        {
            res.pop_back();
        }
        return res;
    }
};
// @lc code=end
