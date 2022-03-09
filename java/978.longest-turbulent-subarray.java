/*
 * @lc app=leetcode id=978 lang=java
 *
 * [978] Longest Turbulent Subarray
 */

// @lc code=start
class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int len = arr.length;
        int res = 1;
        boolean is_upper_pos = true;
        int count = 1;
        for (int i = 1; i != len; ++i)
        {
            if (arr[i] > arr[i - 1])
            {
                if (is_upper_pos)
                {
                    res = Math.max(res, count);
                    count = 2;
                }
                else
                {
                    ++count;
                    is_upper_pos = true;
                }
            }
            else if (arr[i] < arr[i - 1])
            {
                if (is_upper_pos)
                {
                    ++count;
                    is_upper_pos = false;
                }
                else
                {
                    res = Math.max(res, count);
                    count = 2;
                }
            }
            else
            {
                res = Math.max(res, count);
                count = 1;
            }
        }
        return Math.max(res, count);
    }
}
// @lc code=end

