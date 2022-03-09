/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> umap;
        istringstream iss(s1);
        string s;
        while (iss >> s)
        {
            ++umap[s];
        }
        iss.str(s2);
        iss.clear();
        while (iss >> s)
        {
            ++umap[s];
        }
        vector<string> res;
        for (auto &pair : umap)
        {

            if (pair.second == 1)
            {
                res.push_back(pair.first);
            }
        }
        return res;
    }
};
// @lc code=end
