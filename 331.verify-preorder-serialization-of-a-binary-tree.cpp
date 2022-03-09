/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int depth = 0;
        int cur = 0;
        preorder.push_back(',');
        int len = preorder.size();
        while (cur != len)
        {
            if (preorder[cur] != '#')
            {
                ++depth;
                cur = preorder.find(',', cur) + 1;
            }
            else if (depth)
            {
                --depth;
                cur = preorder.find(',', cur) + 1;
            }
            else
            {
                break;
            }
        }
        return cur == len - 2;
    }
};
// @lc code=end
