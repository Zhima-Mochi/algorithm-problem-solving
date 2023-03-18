/*
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string res;
        int w = part.size();
        for (auto c : s)
        {
            res.push_back(c);
            if (res.size() >= w && res.back() == part.back() && res[res.size() - w] == part[0])
            {
                if (res.substr(res.size() - w) == part)
                {
                    res = res.substr(0, res.size() - w);
                }
            }
        }
        return res;
    }
};
// @lc code=end
