/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        sort(wordDict.begin(), wordDict.end());
        unordered_map<char, vector<string>> compactDict;
        for (auto &word : wordDict)
        {
            if (findWay(word, 0, compactDict) == false)
            {
                compactDict[word[0]].push_back(word);
            }
        }
        return findWay(s, 0, compactDict);
    }
    bool findWay(string &s, size_t pos, unordered_map<char, vector<string>> &wordDict)
    {
        if (pos == s.size())
        {
            return true;
        }
        if (wordDict.count(s[pos]) == 0)
        {
            return false;
        }
        vector<string> &dict_list = wordDict[s[pos]];
        for (auto &word : dict_list)
        {
            if (s.substr(pos, word.size()) == word)
            {
                auto len = word.size();
                auto next_pos = pos + len;
                while (s.substr(next_pos, len) == word)
                {
                    next_pos += len;
                }
                auto max_len = dict_list.back().size();
                if (pos + len + len * (max_len / len + 1) > next_pos)
                {
                    next_pos = pos + len;
                }
                else
                {
                    next_pos -= len * (max_len / len + 1);
                }

                if (findWay(s, next_pos, wordDict))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
//"catcatcatccc"\n ["cat","catcatccc"]\n
