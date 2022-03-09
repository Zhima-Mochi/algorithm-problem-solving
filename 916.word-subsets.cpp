/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        string criterion(26, 0);
        for (auto &word : words2)
        {
            string crt(26, 0);
            for (auto c : word)
            {
                ++crt[c - 'a'];
            }
            for (int i = 0; i != 26; ++i)
            {
                criterion[i] = max(criterion[i], crt[i]);
            }
        }

        vector<string> res;
        for (auto &word : words1)
        {
            string count(26, 0);
            for (auto c : word)
            {
                ++count[c - 'a'];
            }
            bool flag = true;
            for (int i = 0; i != 26; ++i)
            {
                if (criterion[i] > count[i])
                {
                    flag = false;
                    break;
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
