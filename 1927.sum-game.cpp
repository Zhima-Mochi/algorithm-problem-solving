/*
 * @lc app=leetcode id=1927 lang=cpp
 *
 * [1927] Sum Game
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool sumGame(string num)
    {
        auto len = num.size();
        auto count_1 = 0, count_2 = 0;
        auto value_1 = 0, value_2 = 0;
        auto bound = len / 2;
        for (int i = 0; i != bound; ++i)
        {
            if (num[i] == '?')
            {
                ++count_1;
            }
            else
            {
                value_1 += num[i] - '0';
            }
        }
        for (int i = bound; i != len; ++i)
        {
            if (num[i] == '?')
            {
                ++count_2;
            }
            else
            {
                value_2 += num[i] - '0';
            }
        }
        return 9 * (count_1 - count_2) / 2 + value_1 != value_2;
    }
};
// @lc code=end