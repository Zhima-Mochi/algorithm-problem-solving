/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeDuplicates(string &s)
    {
        string res;
        for (auto i : s)
        {
            if (res.empty())
            {
                res.push_back(i);
            }
            else
            {
                if (res.back() == i)
                {
                    res.pop_back();
                }
                else
                {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};
// @lc code=end
