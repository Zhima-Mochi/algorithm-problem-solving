/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class TrieNode
{
public:
    TrieNode() = default;
    vector<TrieNode *> next = vector<TrieNode *>(26);
};
class Solution
{
    TrieNode *root = new TrieNode();

public:
    string longestWord(vector<string> &words)
    {
        string res;
        sort(words.begin(), words.end(), [](string &l, string &r)
             { return l.size() < r.size(); });
        for (auto &w : words)
        {
            int w_len = w.size();
            auto cur = root;
            for (int i = 0; i != w_len - 1; ++i)
            {
                if (cur->next[w[i] - 'a'])
                {
                    cur = cur->next[w[i] - 'a'];
                }
                else
                {
                    cur = nullptr;
                    break;
                }
            }
            if (cur)
            {
                cur->next[w[w_len - 1] - 'a'] = new TrieNode();
                if (w_len > res.size() || w_len == res.size() && w < res)
                {
                    res = w;
                }
            }
        }
        return res;
    }
};
// @lc code=end
