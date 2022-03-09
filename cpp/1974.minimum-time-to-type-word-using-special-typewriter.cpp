/*
 * @lc app=leetcode id=1974 lang=cpp
 *
 * [1974] Minimum Time to Type Word Using Special Typewriter
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minTimeToType(string word)
    {
        int res = 0;
        char prev_c = 'a';
        for (auto c : word)
        {
            if (c >= prev_c)
            {
                res += min('z' - c + 1 + prev_c - 'a', c - prev_c) + 1;
            }
            else
            {
                res += min('z' - prev_c + 1 + c - 'a', prev_c - c) + 1;
            }
            prev_c = c;
        }
        return res;
    }
};
// @lc code=end
