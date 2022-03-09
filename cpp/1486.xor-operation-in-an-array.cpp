/*
 * @lc app=leetcode id=1486 lang=cpp
 *
 * [1486] XOR Operation in an Array
 */

// @lc code=start
class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int last = start + 2 * (n - 1);
        if (start % 4 <= 1)
        {

            if (n % 4 == 1)
            {
                return last;
            }
            else if (n % 4 == 2)
            {
                return 2;
            }
            else if (n % 4 == 3)
            {
                return 2 ^ last;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (n % 4 == 1)
            {
                return start;
            }
            else if (n % 4 == 2)
            {
                return start ^ last;
            }
            else if (n % 4 == 3)
            {
                return start ^ 2;
            }
            else
            {
                return start ^ 2 ^ last;
            }
        }
    }
};
// @lc code=end
