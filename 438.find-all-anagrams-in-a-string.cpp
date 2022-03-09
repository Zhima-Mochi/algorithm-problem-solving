/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */
#include <vector>
#include <string>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        int p_len = p.size();
        int s_len = s.size();
        if (s_len < p_len)
        {
            return res;
        }
        vector<int> p_count(26);
        for (auto c : p)
        {
            p_count[c - 'a']++;
        }
        for (int i = 0; i != p_len; ++i)
        {
            p_count[s[i] - 'a']--;
        }
        int diff_count = 0;
        for (auto n : p_count)
        {
            if (n)
            {
                ++diff_count;
            }
        }
        if (diff_count == 0)
        {
            res.push_back(0);
        }
        for (int i = p_len; i != s_len; ++i)
        {
            if (++p_count[s[i - p_len] - 'a'] == 0)
            {
                --diff_count;
            }
            else if (p_count[s[i - p_len] - 'a'] == 1)
            {
                ++diff_count;
            }
            if (--p_count[s[i] - 'a'] == 0)
            {
                --diff_count;
            }
            else if (p_count[s[i] - 'a'] == -1)
            {
                ++diff_count;
            }
            if (diff_count == 0)
            {
                res.push_back(i - p_len + 1);
            }
        }
        return res;
    }
};
// @lc code=end
