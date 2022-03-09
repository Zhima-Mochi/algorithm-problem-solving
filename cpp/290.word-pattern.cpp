/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<char> mp(26);
        unordered_map<string, char> mp_2;
        int blank_pos = -1;
        auto len = pattern.size();
        for (int i = 0; i != len; ++i)
        {
            auto next_pos = s.find(' ', blank_pos + 1);
            auto word = s.substr(blank_pos + 1, next_pos - blank_pos - 1);
            if (mp[pattern[i] - 'a'] != mp_2[word])
            {
                return false;
            }
            mp[pattern[i] - 'a'] = i + 1;
            mp_2[word] = i + 1;
            blank_pos = next_pos;
        }
        return blank_pos == -1;
    }
};
// @lc code=end
