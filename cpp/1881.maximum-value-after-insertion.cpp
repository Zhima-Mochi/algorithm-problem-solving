/*
 * @lc app=leetcode id=1881 lang=cpp
 *
 * [1881] Maximum Value after Insertion
 */
#include <string>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    string maxValue(string n, int x)
    {
        char cx = '0' + x;
        int w = n.size();
        if (n[0] != '-')
        {
            for (int i = 0; i != w; ++i)
            {
                if (cx > n[i])
                {
                    n.insert(i, 1, cx);
                    return n;
                }
            }
            n.push_back(cx);
            return n;
        }
        else
        {
            for (int i = 1; i != w; ++i)
            {
                if (cx < n[i])
                {
                    n.insert(i, 1, cx);
                    return n;
                }
            }
            n.push_back(cx);
            return n;
        }
    }
};
// @lc code=end
