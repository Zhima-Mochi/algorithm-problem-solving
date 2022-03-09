/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
// t:O(sum(len(word) in words)), s:O(sum(len(word) in words))
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        int w = pattern.size();
        vector<string> res;
        for (auto &word : words)
        {
            string p2w(26, 0);
            string w2p(26, 0);
            bool flag = true;
            for (int i = 0; i != w; ++i)
            {
                if (w2p[word[i] - 'a'] || p2w[pattern[i] - 'a'])
                {
                    if (w2p[word[i] - 'a'] != pattern[i] || p2w[pattern[i] - 'a'] != word[i])
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    w2p[word[i] - 'a'] = pattern[i];
                    p2w[pattern[i] - 'a'] = word[i];
                }
            }
            if (flag)
            {
                res.push_back(word);
            }
        }
        return res;
    }
};
// @lc code=end
