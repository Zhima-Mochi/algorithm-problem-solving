/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string makeGood(string s)
    {
        string res;
        for (auto c : s)
        {
            if (res.empty())
            {
                res.push_back(c);
            }
            else
            {
                if (tolower(c) == tolower(res.back()) && c != res.back())
                {
                    res.pop_back();
                }
                else
                {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};
// @lc code=end
