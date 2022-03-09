/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution
{
public:
    int numberOfSteps(int num)
    {
        int count = 0;
        while (num)
        {
            ++count;
            if (num % 2)
            {
                --num;
            }
            else
            {
                num /= 2;
            }
        }
        return count;
    }
};
// @lc code=end
