/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        int width = words.size();
        vector<string> res;
        for (auto &word : words)
        {
            for (int i = 0, word_len = word.size(); i != width; ++i)
            {
                if (words[i].size() >= word_len && words[i] != word && words[i].find(word) != -1)
                {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
