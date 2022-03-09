/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxPower(string s)
    {
        int res = 1;
        int cont = 1;
        for (int i = 1, width = s.size(); i != width; ++i)
        {
            if (s[i - 1] == s[i])
            {
                ++cont;
            }
            else
            {
                res = max(res, cont);
                if (width - i <= res)
                {
                    break;
                }
                cont = 1;
            }
        }
        return max(res, cont);
    }
};
// @lc code=end
