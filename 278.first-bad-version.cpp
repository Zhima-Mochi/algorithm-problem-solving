/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;
        while (left < right)
        {
            auto middle = left + (right - left) / 2;
            if (isBadVersion(middle) == false)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return left;
    }
};
// @lc code=end
