/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class TrieNode
{
public:
    int l = 0;
    TrieNode *child[26] = {};
    TrieNode(int len) : l(len){};
};
class Trie
{
public:
    TrieNode *root = new TrieNode(0);
    void insert(string &s)
    {
        auto cur = root;
        int len = 0;
        for (auto c : s)
        {
            ++len;
            if (!cur->child[c - 'a'])
            {
                cur->child[c - 'a'] = new TrieNode(len);
            }
            cur = cur->child[c - 'a'];
        }
    }
    int getLength()
    {
        vector<TrieNode *> record = {root};
        int res = 0;
        while (!record.empty())
        {
            auto cur = record.back();
            record.pop_back();
            bool has_next = false;

            for (auto n : cur->child)
            {
                if (n)
                {
                    if (has_next)
                    {
                        res += cur->l;
                    }
                    has_next = true;
                    ++res;
                    record.push_back(n);
                }
            }
            if (!has_next)
            {
                ++res;
            }
        }
        return res;
    }
};
class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        auto t = Trie();
        for (auto &&word : words)
        {
            auto reverse_word = word;
            reverse(reverse_word.begin(), reverse_word.end());
            t.insert(reverse_word);
        }
        return t.getLength();
    }
};
// @lc code=end