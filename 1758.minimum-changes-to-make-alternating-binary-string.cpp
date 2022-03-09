/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(string s)
    {
        int width = s.size();
        int cnt = 0;
        for (int i = 0; i != width; ++i)
        {
            if (i % 2 && s[i] == '1')
            {
                ++cnt;
            }
            else if (i % 2 == 0 && s[i] == '0')
            {
                ++cnt;
            }
        }
        return min(cnt, width - cnt);
    }
};
// @lc code=end
