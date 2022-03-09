// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem472.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
// T:O(sum(words[i].length)) S:O(min(sum(words[i].length)*26, 26^max(words[i].length)))
class TrieNode
{
public:
    bool has_word = false;
    TrieNode *children[26] = {};
};
class Trie
{
public:
    TrieNode *root = new TrieNode();
    void insert(string &s)
    {
        auto cur = root;
        for (auto c : s)
        {
            if (!cur->children[c - 'a'])
            {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->has_word = true;
    }
    bool find_word(string &s, int start, int end)
    {
        auto cur = root;
        for (int i = start; i != end; ++i)
        {
            if (!cur->children[s[i] - 'a'])
            {
                return false;
            }
            cur = cur->children[s[i] - 'a'];
        }
        return cur->has_word;
    }
    bool is_concatenated(string &s, int start, int end, vector<bool> &record)
    {
        auto cur = root;
        for (auto i = start; i < end - 1; ++i)
        {
            if (!cur->children[s[i] - 'a'])
            {
                return false;
            }
            cur = cur->children[s[i] - 'a'];
            if (cur->has_word && record[i + 1] == false)
            {
                if (find_word(s, i + 1, end))
                {
                    return true;
                }
                if (is_concatenated(s, i + 1, end, record))
                {
                    insert(s);
                    return true;
                }
                record[i + 1] = true;
            }
        }
        return false;
    }
};
class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        Trie tr = Trie();
        vector<string> res;
        for (auto &&word : words)
        {
            tr.insert(word);
        }
        for (auto &&word : words)
        {
            int end = word.size();
            vector<bool> record(end);
            if (tr.is_concatenated(word, 0, end, record))
            {
                res.push_back(word);
            }
        }
        return res;
    }
};
// @lc code=end
