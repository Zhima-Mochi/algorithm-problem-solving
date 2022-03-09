/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxDepth(string s)
    {
        int depth_num = 0;
        int res = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                ++depth_num;
            }
            else if (c == ')')
            {
                res = max(res, depth_num);
                --depth_num;
            }
        }
        return res;
    }
};
// @lc code=end
