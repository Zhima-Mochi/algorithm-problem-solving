/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num    your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1, right = n;
        while (left < right)
        {
            auto middle = left + (right - left) / 2;
            if (guess(middle) < 0)
            {
                right = middle - 1;
            }
            else if (guess(middle) > 0)
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return left;
    }
};
// @lc code=end
