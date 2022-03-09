/*
 * @lc app=leetcode id=1961 lang=cpp
 *
 * [1961] Check If String Is a Prefix of Array
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        int width = s.size();
        int ind = 0;
        for (auto &&word : words)
        {
            for (auto c : word)
            {
                if (ind == width || c != s[ind])
                {
                    return false;
                }
                else
                {
                    ++ind;
                }
            }
            if (ind == width)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
