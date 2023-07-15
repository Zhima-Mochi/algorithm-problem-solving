/*
 * @lc app=leetcode id=1888 lang=cpp
 *
 * [1888] Minimum Number of Flips to Make the Binary String Alternating
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minFlips(string s)
    {
        int w = s.size();
        vector<vector<int>> memo(2, vector<int>(w + 1));
        int last_0 = 0, last_1 = 0;
        for (int i = 0; i != w; ++i)
        {
            int next_last_0 = 0, next_last_1 = 0;
            next_last_0 = last_1 + (s[i] == '0' ? 0 : 1);
            next_last_1 = last_0 + (s[i] == '1' ? 0 : 1);
            last_0 = next_last_0;
            last_1 = next_last_1;
        }
        int res = w;
        int l0 = last_0, l1 = last_1;
        last_0 = 0, last_1 = 0;
        for (int j = 0; j != w; ++j)
        {
            res = min(res, l1 - ((w - j) % 2 == 0 ? last_1 : last_0) + (j % 2 == 0 ? last_1 : last_0));
            res = min(res, l0 - ((w - j) % 2 == 0 ? last_0 : last_1) + (j % 2 == 0 ? last_0 : last_1));

            int next_last_0 = 0, next_last_1 = 0;
            next_last_0 = last_1 + (s[j] == '0' ? 0 : 1);
            next_last_1 = last_0 + (s[j] == '1' ? 0 : 1);
            last_0 = next_last_0;
            last_1 = next_last_1;
        }
        return res;
    }
};
// @lc code=end
