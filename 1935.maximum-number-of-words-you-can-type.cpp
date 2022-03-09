/*
 * @lc app=leetcode id=1935 lang=cpp
 *
 * [1935] Maximum Number of Words You Can Type
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        string brokenalpha = string(26, 0);
        for (auto a : brokenLetters)
        {
            brokenalpha[a - 'a'] = 1;
        }
        int error_count = 0;
        int res = 0;
        for (auto a : text)
        {
            if (isblank(a))
            {
                if (error_count == 0)
                {
                    ++res;
                }
                error_count = 0;
            }
            else if (error_count > 0)
            {
                continue;
            }
            else if (brokenalpha[a - 'a'])
            {
                ++error_count;
            }
        }
        return res + (error_count == 1 ? 0 : 1);
    }
};
// @lc code=end
