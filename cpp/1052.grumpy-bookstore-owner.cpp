/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(N), s:O(1)
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int res = 0;
        int w = customers.size();
        for (int i = 0; i != w; ++i)
        {
            if (grumpy[i] == 0)
            {
                res += customers[i];
            }
        }
        int add_on = 0;
        for (int i = 0; i != minutes; ++i)
        {
            if (grumpy[i] == 1)
            {
                add_on += customers[i];
            }
        }
        int max_add_on = add_on;
        for (int i = minutes; i != w; ++i)
        {
            if (grumpy[i - minutes] == 1)
            {
                add_on -= customers[i - minutes];
            }
            if (grumpy[i] == 1)
            {
                add_on += customers[i];
            }
            max_add_on = max(add_on, max_add_on);
        }
        return res + max_add_on;
    }
};
// @lc code=end
