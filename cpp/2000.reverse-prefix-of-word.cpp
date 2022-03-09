/*
 * @lc app=leetcode id=2000 lang=cpp
 *
 * [2000] Reverse Prefix of Word
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int pos = word.find(ch);
        if (pos != -1)
        {
            reverse(word.begin(), word.begin() + pos + 1);
        }
        return word;
    }
};
// @lc code=end
