/*
 * @lc app=leetcode id=1967 lang=cpp
 *
 * [1967] Number of Strings That Appear as Substrings in Word
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int res = 0;
        for (auto &&pat : patterns)
        {
            if (word.find(pat) != -1)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
