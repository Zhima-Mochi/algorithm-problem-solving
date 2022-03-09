/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<short> mp(26);
        for (auto s : magazine)
        {
            ++mp[s - 'a'];
        }
        for (auto s : ransomNote)
        {
            if (--mp[s - 'a'] == -1)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
