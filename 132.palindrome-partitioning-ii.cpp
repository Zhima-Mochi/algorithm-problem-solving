/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minCut(string s)
    {
        int len = s.size();
        vector<int> cut_count(len + 1);
        for (int i = 0; i != len + 1; ++i)
        {
            cut_count[i] = i - 1;
        }
        for (int i = 0; i != len; ++i)
        {
            for (int j = 0; i - j >= 0 && i + j < len && s[i + j] == s[i - j]; ++j)
            {
                cut_count[i + j + 1] = min(cut_count[i - j] + 1, cut_count[i + j + 1]);
            }
            for (int j = 1; i - j >= -1 && i + j < len && s[i + j] == s[i - j + 1]; ++j)
            {
                cut_count[i + j + 1] = min(cut_count[i - j + 1] + 1, cut_count[i + j + 1]);
            }
        }
        return cut_count.back();
    }
};
// @lc code=end
