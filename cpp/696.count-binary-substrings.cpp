/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        auto len = s.size();
        auto count_1 = 1;
        auto count_2 = 0;
        int res = 0;
        for (int i = 1; i != len; ++i)
        {
            if (s[i] == s[i - 1])
            {
                ++count_1;
            }
            else
            {
                res += min(count_1, count_2);
                swap(count_1, count_2);
                count_1 = 1;
            }
        }
        res += min(count_1, count_2);
        return res;
    }
};
// @lc code=end
