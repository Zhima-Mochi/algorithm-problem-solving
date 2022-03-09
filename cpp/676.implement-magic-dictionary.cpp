/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class MagicDictionary
{
    unordered_map<int, vector<string>> len_word_map;

public:
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        for (auto &word : dictionary)
        {
            len_word_map[word.size()].push_back(word);
        }
    }

    bool search(string searchWord)
    {
        for (auto &word : len_word_map[searchWord.size()])
        {
            if (searchWord == word)
            {
                continue;
            }
            int different = 0;
            for (int i = 0, width = searchWord.size(); i != width; ++i)
            {
                if (searchWord[i] != word[i])
                {
                    ++different;
                    if (different > 1)
                    {
                        break;
                    }
                }
            }
            if (different == 1)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

// class MagicDictionary
// {
//     unordered_map<string, vector<char>> replaced_word_map;

// public:
//     MagicDictionary()
//     {
//     }

//     void buildDict(vector<string> dictionary)
//     {
//         for (auto &word : dictionary)
//         {
//             for (int i = 0, width = word.size(); i != width; ++i)
//             {
//                 char replaced_char = word[i];
//                 word[i] = '*';
//                 replaced_word_map[word].push_back(replaced_char);
//                 word[i] = replaced_char;
//             }
//         }
//     }

//     bool search(string searchWord)
//     {
//         for (int i = 0, width = searchWord.size(); i != width; ++i)
//         {
//             char replaced_char = searchWord[i];
//             searchWord[i] = '*';
//             if (replaced_word_map.count(searchWord))
//             {
//                 for (auto c : replaced_word_map[searchWord])
//                 {
//                     if (c != replaced_char)
//                     {
//                         return true;
//                     }
//                 }
//             }
//             searchWord[i] = replaced_char;
//         }
//         return false;
//     }
// };