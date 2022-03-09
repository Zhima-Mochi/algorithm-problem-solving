/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int len = word.size();
        if (len > 1)
        {
            if (islower(word[0]) && isupper(word[1]))
            {
                return false;
            }
            for (int i = 2; i < len; ++i)
            {
                if (islower(word[i]) != islower(word[1]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
