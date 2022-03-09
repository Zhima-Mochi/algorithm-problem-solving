/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        if (targetCapacity > jug1Capacity + jug2Capacity)
        {
            return false;
        }
        if (targetCapacity % jug1Capacity == 0 || targetCapacity % jug2Capacity == 0)
        {
            return true;
        }

        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};
// @lc code=end