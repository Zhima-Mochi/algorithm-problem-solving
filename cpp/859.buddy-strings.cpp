/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        int len = s.size();
        if (len != goal.size())
        {
            return false;
        }
        string diff_s, diff_goal;
        string count(26, 0);
        bool has_repeat = false;
        for (int i = 0; i != len; ++i)
        {
            if (!has_repeat)
            {
                ++count[s[i] - 'a'];
                if (count[s[i] - 'a'] == 2)
                {
                    has_repeat = true;
                }
            }
            if (s[i] != goal[i])
            {
                if (diff_s.size() == 2)
                {
                    return false;
                }
                else if (!diff_s.empty())
                {
                    if (diff_s[0] != goal[i] || diff_goal[0] != s[i])
                    {
                        return false;
                    }
                }
                diff_s.push_back(s[i]);
                diff_goal.push_back(goal[i]);
            }
        }
        return diff_s.size() == 2 || diff_s.size() == 0 && has_repeat;
    }
};
// @lc code=end

