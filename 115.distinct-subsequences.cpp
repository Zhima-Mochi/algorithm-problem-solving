/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        if (s == t)
        {
            return 1;
        }
        if (!check_has_substring(s, t))
        {
            return 0;
        }
        int res = 0;
        unordered_map<char, vector<string>> pre_word_map;
        unordered_map<string, long> match_word_count;
        int len = t.size();
        for (int i = 1; i != len; ++i)
        {
            auto pre_word = t.substr(0, i);
            pre_word_map[t[i]].push_back(pre_word);
        }
        auto first_word_string = t.substr(0, 1);
        for (auto c : s)
        {
            for (auto iter = pre_word_map[c].rbegin(), iter_end = pre_word_map[c].rend(); iter != iter_end; ++iter)
            {
                auto pre_word = *iter;
                auto extended_pre_word = pre_word + c;
                match_word_count[extended_pre_word] += match_word_count[pre_word];
            }
            if (c == t[0])
            {
                ++match_word_count[first_word_string];
            }
        }
        return match_word_count[t];
    }
    bool check_has_substring(string &s, string &t)
    {
        if (t.size() > s.size())
        {
            return false;
        }
        int pos = 0;
        for (auto c : t)
        {
            auto next_pos = s.find(c, pos);
            if (next_pos == -1)
            {
                return false;
            }
            else
            {
                pos = next_pos + 1;
            }
        }
        return true;
    }
};
// @lc code=end
