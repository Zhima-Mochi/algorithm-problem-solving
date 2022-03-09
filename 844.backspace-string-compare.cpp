/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int left = s.size() - 1;
        int right = t.size() - 1;
        while (left != -1 && right != -1)
        {
            shift(s, left);
            shift(t, right);
            if (left == -1 && right == -1)
            {
                return true;
            }
            else if (left == -1 || right == -1)
            {
                return false;
            }
            else if (s[left] != t[right])
            {
                return false;
            }
            else
            {
                --left;
                --right;
            }
        }
        shift(s, left);
        shift(t, right);
        return left == -1 && right == -1;
    }
    void shift(string &str, int &cur)
    {
        if (cur == -1)
        {
            return;
        }
        int count = 0;
        while (cur != -1 && str[cur] == '#')
        {
            ++count;
            --cur;
            while (cur != -1 && str[cur] == '#')
            {
                ++count;
                --cur;
            }
            while (count && cur != -1 && str[cur] != '#')
            {
                --cur;
                --count;
            }
        }
    }
};
// @lc code=end
