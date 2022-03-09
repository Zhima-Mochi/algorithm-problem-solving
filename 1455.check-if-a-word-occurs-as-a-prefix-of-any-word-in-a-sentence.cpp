/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int pos = 0;
        int searchWord_width = searchWord.size();
        int index = 1;
        while (pos != -1)
        {
            pos = sentence.find_first_not_of(' ', pos);
            bool match = true;
            for (int i = 0; i != searchWord_width; ++i)
            {
                if (sentence[pos + i] != searchWord[i])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return index;
            }
            ++index;
            pos = sentence.find_first_of(' ', pos);
        }
        return -1;
    }
};
// @lc code=end
