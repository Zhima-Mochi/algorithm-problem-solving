/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class trie_node
{
public:
    trie_node() = default;
    vector<trie_node *> wordDict = vector<trie_node *>(26);
    bool existed_word = false;
};

class Trie
{
public:
    Trie() : root(new trie_node())
    {
    }

    void insert(string &word)
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
                cur->wordDict[s - 'a'] = new trie_node();
                cur = cur->wordDict[s - 'a'];
            }
        }
        cur->existed_word = true;
    }
    //If the word is found, do not leave it in dictionary
    void del(string &word)
    {
        auto cur = root;
        vector<trie_node *> st = {root};
        for (auto &s : word)
        {
            cur = cur->wordDict[s - 'a'];
            st.push_back(cur);
        }
        cur->existed_word = false;
        while (st.size() > 1 && st.back()->existed_word == false)
        {
            auto elem = st.back();
            st.pop_back();
            bool allNull = hasNoChild(elem);
            if (allNull)
            {
                for (auto child : st.back()->wordDict)
                {
                    if (child == elem)
                    {
                        child = nullptr;
                        //delete elem; // Should use shared ptr
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }

    trie_node *root;
    static bool hasNoChild(trie_node *root)
    {
        bool is_empty = true;
        for (auto elem : root->wordDict)
        {
            if (elem)
            {
                is_empty = false;
                break;
            }
        }
        return is_empty;
    }
};
class Solution
{
    int height;
    int width;
    Trie dict;

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        height = board.size();
        width = board[0].size();

        vector<string> res;
        res.reserve(words.size());
        for (auto &word : words)
        {
            dict.insert(word);
        }
        for (int i = 0; i != height; ++i)
        {
            if (Trie::hasNoChild(dict.root))
            {
                break;
            }
            for (int j = 0; j != width; ++j)
            {
                if (Trie::hasNoChild(dict.root))
                {
                    break;
                }
                search(i, j, board, "", dict.root, res);
            }
        }
        return res;
    }
    void search(int i, int j, vector<vector<char>> &board, string current_matched_word, trie_node *cur, vector<string> &res)
    {
        if (i < 0 || j < 0 || i >= height || j >= width)
        {
            return;
        }
        if (board[i][j] < 'a' || !cur->wordDict[board[i][j] - 'a'])
        {
            return;
        }
        auto next_cur = cur->wordDict[board[i][j] - 'a'];
        current_matched_word.push_back(board[i][j]);
        if (next_cur->existed_word)
        {
            res.push_back(current_matched_word);
            dict.del(current_matched_word);
        }
        if (Trie::hasNoChild(next_cur))
        {
            return;
        }
        board[i][j] ^= -1;
        search(i - 1, j, board, current_matched_word, next_cur, res);
        search(i, j + 1, board, current_matched_word, next_cur, res);
        search(i + 1, j, board, current_matched_word, next_cur, res);
        search(i, j - 1, board, current_matched_word, next_cur, res);
        board[i][j] ^= -1;
    }
};
// @lc code=end
