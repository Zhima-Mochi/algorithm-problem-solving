/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class trie_node
{
public:
    trie_node() = default;
    trie_node(char w) : word(w) {}
    char word = ' ';
    vector<trie_node *> wordDict = vector<trie_node *>(26);
    bool existed_word = false;
};
class WordDictionary
{
private:
    trie_node *root;

public:
    /** Initialize your data structure here. */
    WordDictionary() : root(new trie_node())
    {
    }

    void addWord(string word)
    {
        auto cur = root;
        for (auto &s : word)
        {
            if (!cur->wordDict[s - 'a'])
            {
                cur->wordDict[s - 'a'] = new trie_node(s);
            }

            cur = cur->wordDict[s - 'a'];
        }
        cur->existed_word = true;
    }

    bool search(string word)
    {
        return substrMatch(root, word, 0);
    }
    bool substrMatch(trie_node *root, string &s, int pos)
    {
        if (pos == s.size())
        {
            return root->existed_word;
        }
        if (s[pos] != '.')
        {
            if (root->wordDict[s[pos] - 'a'])
            {
                return substrMatch(root->wordDict[s[pos] - 'a'], s, pos + 1);
            }
            else
            {
                return false;
            }
        }
        else
        {
            for (int i = 0; i != 26; ++i)
            {
                if (root->wordDict[i])
                {
                    if (substrMatch(root->wordDict[i], s, pos + 1))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
