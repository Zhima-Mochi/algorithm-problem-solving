/*
 * @lc app=leetcode id=1816 lang=cpp
 *
 * [1816] Truncate Sentence
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string res;
        int word_cnt = 0;
        for (auto c : s)
        {
            if (isblank(c))
            {
                ++word_cnt;
                if (word_cnt == k)
                {
                    break;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};
// @lc code=end
