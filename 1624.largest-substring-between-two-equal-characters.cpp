/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> prev_alpha_pos(26, -1);
        int res = -1;
        for (int i = 0, width = s.size(); i != width; ++i)
        {
            if (prev_alpha_pos[s[i] - 'a'] != -1)
            {
                res = max(res, i - prev_alpha_pos[s[i] - 'a'] - 1);
            }
            else
            {
                prev_alpha_pos[s[i] - 'a'] = i;
            }
        }
        return res;
    }
};
// @lc code=end
