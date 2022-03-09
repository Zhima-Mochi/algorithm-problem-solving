/*
 * @lc app=leetcode id=754 lang=cpp
 *
 * [754] Reach a Number
 */
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int reachNumber(int target)
    {
        if (target < 0)
        {
            target *= -1;
        }
        int step = pow(target * 2, 0.5);
        --step;
        int lower_bound = (1 + step) * step / 2;
        while (lower_bound + step + 1 <= target)
        {
            ++step;
            lower_bound += step;
        }
        int rest = -(target - lower_bound);
        while (rest)
        {
            rest += ++step;
            rest %= 2;
        }
        return step;
    }
};
// @lc code=end