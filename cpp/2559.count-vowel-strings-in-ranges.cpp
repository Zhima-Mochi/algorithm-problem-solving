/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
    vector<bool> is_vowel = vector<bool>(26);
    bool valid(string &s)
    {
        return is_vowel[s.front() - 'a'] && is_vowel[s.back() - 'a'];
    }

public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        is_vowel['a' - 'a'] = is_vowel['e' - 'a'] = is_vowel['i' - 'a'] = is_vowel['o' - 'a'] = is_vowel['u' - 'a'] = true;
        int w = words.size();
        vector<int> ac(w + 1);
        for (int i = 0; i != w; ++i)
        {
            ac[i + 1] = ac[i] + valid(words[i]);
        }
        vector<int> res;
        for (auto &q : queries)
        {
            res.push_back(ac[q[1] + 1] - ac[q[0]]);
        }
        return res;
    }
};
// @lc code=end
