/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int odd_count = 0;
        int even_count = 0;
        for (auto n : position)
        {
            if (n % 2)
            {
                ++odd_count;
            }
            else
            {
                ++even_count;
            }
        }
        return min(odd_count, even_count);
    }
};
// @lc code=end
