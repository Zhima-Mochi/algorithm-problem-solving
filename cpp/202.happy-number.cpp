/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int next_num(int n)
    {
        auto new_n = 0;
        while (n)
        {
            new_n += (n % 10) * (n % 10);
            n /= 10;
        }
        return new_n;
    }

public:
    bool isHappy(int n)
    {
        int n1 = n, n2 = n;
        do
        {
            n1 = next_num(n1);
            if ((n2 = next_num(n2)) == 1)
            {
                return true;
            }
            if ((n2 = next_num(n2)) == 1)
            {
                return true;
            }
        } while (n1 != n2);
        return false;
    }
};
// @lc code=end
