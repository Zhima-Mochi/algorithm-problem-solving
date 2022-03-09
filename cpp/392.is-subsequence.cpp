/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        auto pos = -1;
        t.push_back(0);
        for (auto c : s)
        {
            pos = t.find(c, pos + 1);
            if (pos == -1)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
