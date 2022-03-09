/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int len = s.size();
        if (len != goal.size())
        {
            return false;
        }
        vector<int> failure(len, -1);
        for (int i = 1, j = -1; i < len; ++i)
        {
            while (j != -1 && goal[j + 1] != goal[i])
            {
                j = failure[j];
            }
            if (goal[j + 1] == goal[i])
            {
                failure[i] = ++j;
            }
        }
        auto cur = -1;
        for (int i = 0; i != 2 * len && cur != len; ++i)
        {
            while (cur != -1 && s[i % len] != goal[cur + 1])
            {
                cur = failure[cur];
            }
            if (goal[cur + 1] == s[i % len])
            {
                ++cur;
            }
            else
            {
                if (i + len - cur >= 2 * len)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
