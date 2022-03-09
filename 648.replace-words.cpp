/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class TrieNode
{
public:
    bool has_word;
    string word;
    TrieNode *next[26];
    TrieNode() = default;
    TrieNode(bool _has_word) : has_word(_has_word) {}
};
class Solution
{
    TrieNode *root = new TrieNode();
    int width;

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        width = sentence.size();
        for (auto &dict : dictionary)
        {
            auto cur = root;
            for (auto c : dict)
            {
                if (!cur->next[c - 'a'])
                {
                    cur->next[c - 'a'] = new TrieNode();
                }
                cur = cur->next[c - 'a'];
                if (cur->has_word)
                {
                    break;
                }
            }
            if (!cur->has_word)
            {
                cur->has_word = true;
                cur->word = dict;
                fill_n(cur->next, 26, nullptr);
            }
        }
        int pos = 0;
        string res;
        while (true)
        {
            string dict_word = replaced_word(root, sentence, pos);
            int next_pos = sentence.find(' ', pos);
            if (dict_word == "")
            {
                res.append(sentence.substr(pos, next_pos - pos));
            }
            else
            {
                res.append(dict_word);
            }
            if (next_pos != -1)
            {
                res.push_back(' ');
                pos = next_pos + 1;
            }
            else
            {
                break;
            }
        }
        return res;
    }
    string replaced_word(TrieNode *root, string &sentence, int pos)
    {
        while (pos != width && sentence[pos] != ' ')
        {
            if (root->next[sentence[pos] - 'a'])
            {
                root = root->next[sentence[pos] - 'a'];
                if (root->has_word)
                {
                    break;
                }
            }
            else
            {
                return "";
            }
            ++pos;
        }
        return root->word;
    }
};
// @lc code=end
