/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        // return numBottles + (numBottles - 1) / (numExchange - 1);
        int res = numBottles;
        int rest_bottles = numBottles;
        while (rest_bottles >= numExchange)
        {
            int exchanged_bottles = rest_bottles / numExchange;
            res += exchanged_bottles;
            rest_bottles = rest_bottles % numExchange + exchanged_bottles;
        }
        return res;
    }
};
// @lc code=end
