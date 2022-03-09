/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int w1_w = word1.size();
        int w2_w = word2.size();
        int min_w = min(w1_w, w2_w);
        string res;
        for (int i = 0; i != min_w; ++i)
        {
            res.push_back(word1[i]);
            res.push_back(word2[i]);
        }
        if (w1_w > min_w)
        {
            res.append(word1.substr(min_w));
        }
        else if (w2_w > min_w)
        {
            res.append(word2.substr(min_w));
        }
        return res;
    }
};
// @lc code=end
