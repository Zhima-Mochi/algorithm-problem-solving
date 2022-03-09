/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int len_g = g.size(), len_s = s.size();
        auto left = 0, right = 0;
        int res = 0;
        while (left != len_g && right != len_s)
        {
            if (g[left] <= s[right])
            {
                ++left, ++right;
                ++res;
            }
            else
            {
                ++right;
            }
        }
        return res;
    }
};
// @lc code=end
