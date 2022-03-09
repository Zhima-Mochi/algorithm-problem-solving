/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int w = s.size();
        unordered_map<string, int> dict_idx;
        int dict_word_maxlen = 0;
        int idx = 0;
        for (auto &s : wordDict)
        {
            dict_idx[s] = idx++;
            dict_word_maxlen = max(dict_word_maxlen, static_cast<int>(s.size()));
        }
        vector<string> res;
        vector<bool> no_sol_flag(w + 1);
        function<bool(vector<int> &, int)> backtracking = [&](vector<int> &str_idx, int pos)
        {
            if (pos == w)
            {
                string sol_word;
                for (auto idx : str_idx)
                {
                    if (sol_word == "")
                    {
                        sol_word += wordDict[idx];
                    }
                    else
                    {
                        sol_word += " ";
                        sol_word += wordDict[idx];
                    }
                }
                res.push_back(sol_word);
                return true;
            }
            if (no_sol_flag[pos])
            {
                return false;
            }
            string next_word;
            bool has_sol = false;
            for (int i = pos; i < min(w, pos + dict_word_maxlen); ++i)
            {
                next_word.push_back(s[i]);
                if (dict_idx.count(next_word))
                {
                    str_idx.push_back(dict_idx[next_word]);
                    if (backtracking(str_idx, i + 1))
                    {
                        has_sol = true;
                    }
                    str_idx.pop_back();
                }
            }
            if (!has_sol)
            {
                no_sol_flag[pos] = true;
            }
            return has_sol;
        };
        vector<int> str_idx;
        backtracking(str_idx,0);
        return res;
    }
};
// @lc code=end
