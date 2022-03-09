/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a_num = 0, b_num = 0;
        int len = secret.size();
        unordered_map<int, short> sec_map, gue_map;
        for (int i = 0; i != len; ++i)
        {
            if (secret[i] == guess[i])
            {
                ++a_num;
            }
            else
            {
                ++sec_map[secret[i]];
                ++gue_map[guess[i]];
            }
        }
        for (auto &pair : sec_map)
        {
            if (gue_map.count(pair.first))
            {
                b_num += min(pair.second, gue_map[pair.first]);
            }
        }
        return to_string(a_num) + 'A' + to_string(b_num) + 'B';
    }
};
// @lc code=end
