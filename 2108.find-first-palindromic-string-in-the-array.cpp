/*
 * @lc app=leetcode id=2108 lang=cpp
 *
 * [2108] Find First Palindromic String in the Array
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (auto &&word : words)
        {
            bool flag = true;
            for (int i = 0, w = word.size(); i != w / 2; ++i)
            {
                if (word[i] != word[w - 1 - i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return word;
            }
        }
        return "";
    }
};
// @lc code=end
