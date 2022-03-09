/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        const string vowel = "aeiouAEIOU";
        while (left < right)
        {
            while (vowel.find(s[left]) == -1)
            {
                ++left;
                if (left == right)
                {
                    return s;
                }
            }
            while (vowel.find(s[right]) == -1)
            {
                --right;
                if (left == right)
                {
                    return s;
                }
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
// @lc code=end
