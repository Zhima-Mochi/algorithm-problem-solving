/*
 * @lc app=leetcode id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

// @lc code=start
class Solution
{
public:
    int flipLights(int n, int presses)
    {
        if (presses == 0)
        {
            return 1;
        }
        else if (presses == 1)
        {
            if (n == 1)
            {
                return 2;
            }
            else if (n == 2)
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
        else if (presses == 2)
        {
            if (n == 1)
            {
                return 2;
            }
            else if (n == 2)
            {
                return 4;
            }
            else
            {
                return 7;
            }
        }
        else
        {
            if (n == 1)
            {
                return 2;
            }
            else if (n == 2)
            {
                return 4;
            }
            else
            {
                return 8;
            }
        }
    }
};
// @lc code=end
