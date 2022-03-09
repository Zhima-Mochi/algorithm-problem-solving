/*
 * @lc app=leetcode id=970 lang=cpp
 *
 * [970] Powerful Integers
 */
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
// t:O(log^2(bound)), s:O(log^2(bound))
class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        vector<int> res;
        unordered_set<int> val;
        if (x == y)
        {
            for (long long _x = 1; _x <= bound; _x *= x)
            {
                for (long long _y = 1; _y <= _x && _y + _x <= bound; _y *= y)
                {
                    val.insert(_y + _x);
                    if (y == 1)
                    {
                        break;
                    }
                }
                if (x == 1)
                {
                    break;
                }
            }
        }
        else
        {
            for (long long _x = 1; _x <= bound; _x *= x)
            {
                for (long long _y = 1; _y + _x <= bound; _y *= y)
                {
                    val.insert(_y + _x);
                    if (y == 1)
                    {
                        break;
                    }
                }
                if (x == 1)
                {
                    break;
                }
            }
        }
        res = vector<int>(val.begin(), val.end());
        return res;
    }
};
// @lc code=end
