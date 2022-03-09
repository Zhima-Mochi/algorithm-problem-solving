/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int window_len = s1.size();
        int s2_len = s2.size();
        if (window_len > s2_len)
        {
            return false;
        }
        vector<int> stat(26);
        auto all_zero = stat;
        for (char c : s1)
        {
            --stat[c - 'a'];
        }
        for (int i = 0; i != window_len; ++i)
        {
            ++stat[s2[i] - 'a'];
        }
        if (stat == all_zero)
        {
            return true;
        }
        for (int i = window_len; i != s2_len; ++i)
        {

            ++stat[s2[i] - 'a'];
            --stat[s2[i - window_len] - 'a'];
            if (stat == all_zero)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
