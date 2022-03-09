/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        string count(26, ' ');
        for (auto &n : s)
        {
            ++count[n - 'a'];
        }
        for (auto &n : t)
        {
            --count[n - 'a'];
        }
        return count == string(26, ' ');
    }
};
// @lc code=end
