/*
 * @lc app=leetcode id=1880 lang=cpp
 *
 * [1880] Check if Word Equals Summation of Two Words
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    int strToNum(string s)
    {
        int res = 0;
        for (auto c : s)
        {
            res *= 10;
            res += c - 'a';
        }
        return res;
    }

public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        return strToNum(firstWord) + strToNum(secondWord) == strToNum(targetWord);
    }
};
// @lc code=end
