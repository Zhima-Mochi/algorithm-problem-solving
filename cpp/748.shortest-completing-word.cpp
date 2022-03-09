/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        vector<int> p = {17, 13, 11, 7, 5, 3, 2};
        int licenseVal = 1;
        unordered_map<char, short> umap;
        for (auto c : licensePlate)
        {
            if (isalpha(c))
            {
                c = tolower(c);
                if (umap.count(c))
                {
                    licenseVal *= umap[c];
                }
                else
                {
                    umap[c] = p.back();
                    licenseVal *= p.back();
                    p.pop_back();
                }
            }
        }
        string res = string(16, '0');
        int len = words.size();
        for (int i = 0; i != len; ++i)
        {
            if (words[i].size() >= res.size())
            {
                continue;
            }
            auto licenseCopyVal = licenseVal;
            for (auto w : words[i])
            {
                if (umap.count(w))
                {
                    if (licenseCopyVal % umap[w] == 0)
                    {
                        licenseCopyVal /= umap[w];
                    }
                }
                if (licenseCopyVal == 1)
                {
                    res = words[i];
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
