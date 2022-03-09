/*
 * @lc app=leetcode id=521 lang=cpp
 *
 * [521] Longest Uncommon Subsequence I
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a != b)
        {
            return max(a.size(), b.size());
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end
