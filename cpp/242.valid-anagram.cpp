/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> count(26, 0);
        for (auto &n : s)
        {
            ++count[n - 'a'];
        }
        for (auto &n : t)
        {
            --count[n - 'a'];
        }
        return count == vector<int>(26, 0);
    }
};
// @lc code=end
