/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (!isalpha(s[left]))
            {
                ++left;
            }
            else if (!isalpha(s[right]))
            {
                --right;
            }
            else
            {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};
// @lc code=end
