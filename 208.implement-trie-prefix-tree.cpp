/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Trie
{
public:
    /** Initialize your data structure here. */
    Trie() : root(new trie_node())
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto cur = root;
        for (auto &s : word)
        {
            if (cur->wordDict[s - 'a'])
            {
                cur = cur->wordDict[s - 'a'];
            }
            else
            {
                cur->wordDict[s - 'a'] = new trie_node(s);
                cur = cur->wordDict[s - 'a'];
            }
        }
        cur->existed_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto cur = root;
        for (auto &s : word)
        {
            if (cur->wordDict[s - 'a'])
            {
                cur = cur->wordDict[s - 'a'];
            }
            else
            {
                return false;
            }
        }
        return cur->existed_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto cur = root;
        for (auto &s : prefix)
        {
            if (cur->wordDict[s - 'a'])
            {
                cur = cur->wordDict[s - 'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
    }

private:
    class trie_node
    {
    public:
        trie_node() = default;
        trie_node(char w) : word(w) {}
        char word = ' ';
        vector<trie_node *> wordDict = vector<trie_node *>(26);
        bool existed_word = false;
    };
    trie_node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
