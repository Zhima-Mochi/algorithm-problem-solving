/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */
class MountainArray
{
public:
    int get(int index);
    int length();
};
// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int w = mountainArr.length();
        int left = 1, right = w - 1;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            int slope = mountainArr.get(mid) - mountainArr.get(mid - 1);
            if (slope > 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        int peak = left - 1;
        left = 0, right = peak;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (mountainArr.get(left) == target)
        {
            return left;
        }
        left = peak + 1, right = w - 1;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) > target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (mountainArr.get(left) == target)
        {
            return left;
        }
        return -1;
    }
};
// @lc code=end
