/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> records;
        for (auto &word : words)
        {
            ++records[word];
        }
        int s_w = s.size();
        int w_w = words.size();
        int word_len = words[0].size();
        int match_len = word_len * w_w;
        vector<int> res;
        for (int i = 0; i != word_len; ++i)
        {
            int idx = i;
            unordered_map<string, int> seen;
            int next_idx = idx;
            while (idx + match_len <= s_w)
            {
                string comp_str = s.substr(next_idx, word_len);
                next_idx += word_len;
                if (!records.count(comp_str))
                {
                    idx = next_idx;
                    seen.clear();
                }
                else
                {
                    if (++seen[comp_str] > records[comp_str])
                    {
                        while (idx + match_len <= s_w && seen[comp_str] > records[comp_str])
                        {
                            --seen[s.substr(idx, word_len)];
                            idx += word_len;
                        }
                    }
                    if (next_idx == idx + match_len)
                    {
                        res.push_back(idx);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     vector<int> findSubstring(string s, vector<string> &words)
//     {
//         unordered_set<string> records;
//         for (auto &word : words)
//         {
//             records.insert(word);
//         }
//         int s_w = s.size();
//         int w_w = words.size();
//         int word_len = words[0].size();
//         int match_len = word_len * w_w;
//         vector<int> res;
//         int idx = 0;
//         while (idx + match_len <= s_w)
//         {
//             vector<bool> seen(w_w, false);
//             int next_idx = idx;
//             while (next_idx != idx + match_len)
//             {
//                 bool flag = false;
//                 string comp_str = s.substr(next_idx, word_len);
//                 for (int i = 0; i != w_w; ++i)
//                 {
//                     if (!seen[i])
//                     {
//                         if (comp_str == words[i])
//                         {
//                             seen[i] = true;
//                             next_idx += word_len;
//                             comp_str = s.substr(next_idx, word_len);
//                             flag = true;
//                             break;
//                         }
//                     }
//                 }
//                 if (!flag)
//                 {
//                     break;
//                 }
//             }
//             if (next_idx == idx + match_len)
//             {
//                 res.push_back(idx);
//                 while (next_idx < s_w && s[idx] == s[next_idx])
//                 {
//                     ++idx;
//                     ++next_idx;
//                     if (records.count(s.substr(idx, word_len)) && records.count(s.substr(next_idx - word_len, word_len)))
//                     {
//                         res.push_back(idx);
//                     }
//                 }
//                 ++idx;
//             }
//             else
//             {
//                 ++idx;
//             }
//         }
//         return res;
//     }
// };