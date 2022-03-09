/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<short> word_count(26);
        for (auto s : words[0])
        {
            ++word_count[s - 'a'];
        }
        for (const auto &word : words)
        {
            vector<short> cur_word_count(26);
            for (auto s : word)
            {
                if (word_count[s - 'a'] == 0)
                {
                    continue;
                }
                ++cur_word_count[s - 'a'];
            }
            for (int i = 0; i != 26; ++i)
            {
                word_count[i] = min(word_count[i], cur_word_count[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i != 26; ++i)
        {
            while (word_count[i])
            {
                res.push_back(string(1, 'a' + i));
                --word_count[i];
            }
        }
        return res;
    }
};
// @lc code=end
