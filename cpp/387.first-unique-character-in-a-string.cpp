/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<short> mp(26);
        vector<int> pos(26);
        auto len = s.size();
        for (int i = 0; i != len; ++i)
        {
            ++mp[s[i] - 'a'];
            pos[s[i] - 'a'] = i;
        }
        if (len < 10)
        {
            for (int i = 0; i != len; ++i)
            {
                if (mp[s[i] - 'a'] == 1)
                {
                    return i;
                }
            }
            return -1;
        }
        else
        {
            int res = len;
            for (int i = 0; i != 26; ++i)
            {
                if (mp[i] == 1)
                {
                    res = min(res, pos[i]);
                }
            }
            return res == len ? -1 : res;
        }
    }
};
// @lc code=end
