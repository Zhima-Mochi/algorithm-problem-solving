/*
 * @lc app=leetcode id=966 lang=cpp
 *
 * [966] Vowel Spellchecker
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
// @lc code=start

class Solution
{
public:
    string vowels = "aeiou";
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_set<string> exact;
        unordered_map<string, string> lower;
        unordered_map<string, string> del_vowel;
        for (auto &word : wordlist)
        {
            exact.insert(word);
            string lower_word;
            string del_vowel_word;
            for (auto c : word)
            {
                c=tolower(c);
                lower_word.push_back(c);
                if (vowels.find(c) != -1)
                {
                    del_vowel_word.push_back('_');
                }
                else
                {
                    del_vowel_word.push_back(c);
                }
            }
            if (!lower.count(lower_word))
            {
                lower[lower_word] = word;
            }
            if (!del_vowel.count(del_vowel_word))
            {
                del_vowel[del_vowel_word] = word;
            }
        }
        vector<string> res;
        for (auto &query : queries)
        {
            if (exact.count(query))
            {
                res.push_back(query);
            }
            else
            {
                string lower_word;
                string del_vowel_word;
                for (auto c : query)
                {
                    c=tolower(c);
                    lower_word.push_back(c);
                    if (vowels.find(c) != -1)
                    {
                        del_vowel_word.push_back('_');
                    }
                    else
                    {
                        del_vowel_word.push_back(c);
                    }
                }
                if (lower.count(lower_word))
                {
                    res.push_back(lower[lower_word]);
                }
                else if (del_vowel.count(del_vowel_word))
                {
                    res.push_back(del_vowel[del_vowel_word]);
                }
                else
                {
                    res.push_back("");
                }
            }
        }
        return res;
    }
};
// @lc code=end
