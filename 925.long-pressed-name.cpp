/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int left = 0, right = 0;
        int name_len = name.size(), typed_len = typed.size();
        name.push_back('A');
        typed.push_back('A');
        while (left != name_len && right != typed_len)
        {
            if (name[left] == typed[right])
            {
                ++left, ++right;
                if (name[left] != name[left - 1])
                {
                    while (typed[right] == name[left - 1])
                    {
                        ++right;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        return left == name_len && right == typed_len;
    }
};
// @lc code=end
