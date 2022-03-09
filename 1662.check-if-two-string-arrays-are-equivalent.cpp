/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int word1_width = word1.size();
        int word2_width = word2.size();
        int word1_pos = 0;
        int word2_pos = 0;
        int word1_word_pos = 0;
        int word2_word_pos = 0;
        int word1_word_width = word1[0].size();
        int word2_word_width = word2[0].size();
        while (true)
        {
            if (word1_word_pos == word1_word_width)
            {
                ++word1_pos;
                if (word1_pos != word1_width)
                {
                    word1_word_width = word1[word1_pos].size();
                }
                word1_word_pos = 0;
            }
            if (word2_word_pos == word2_word_width)
            {
                ++word2_pos;
                if (word2_pos != word2_width)
                {
                    word2_word_width = word2[word2_pos].size();
                }
                word2_word_pos = 0;
            }
            if (word1_pos != word1_width && word2_pos != word2_width)
            {
                if (word1[word1_pos][word1_word_pos] != word2[word2_pos][word2_word_pos])
                {
                    return false;
                }
                else
                {
                    ++word1_word_pos;
                    ++word2_word_pos;
                }
            }
            else
            {
                break;
            }
        }
        return word1_pos == word1_width && word2_pos == word2_width;
    }
};
// @lc code=end
