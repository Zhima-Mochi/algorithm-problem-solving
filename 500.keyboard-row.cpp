/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        unordered_map<char, short> umap;
        const string s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "zxcvbnm";
        for (auto c : s1)
        {
            umap[c] = 1;
            umap[toupper(c)] = 1;
        }
        for (auto c : s2)
        {
            umap[c] = 2;
            umap[toupper(c)] = 2;
        }
        for (auto c : s3)
        {
            umap[c] = 4;
            umap[toupper(c)] = 4;
        }
        vector<string> res;
        for (auto &word : words)
        {
            int len = word.size();
            auto base = umap[word[0]];
            bool same_base = true;
            for (int i = 1; i < len; ++i)
            {
                if ((umap[word[i]] & base) == 0)
                {
                    same_base = false;
                    break;
                }
            }
            if (same_base)
            {
                res.push_back(word);
            }
        }
        return res;
    }
};
// @lc code=end
