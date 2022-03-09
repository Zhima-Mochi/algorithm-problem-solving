import java.util.Arrays;

/*
 * @lc app=leetcode id=1313 lang=java
 *
 * [1313] Decompress Run-Length Encoded List
 */

// @lc code=start
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int resLen = 0;
        for (int i = 0; i < nums.length; i += 2) {
            resLen += nums[i];
        }
        int[] res = new int[resLen];
        int tailInd = 0;
        for (int i = 0; i != nums.length; i += 2) {
            Arrays.fill(res, tailInd, tailInd + nums[i], nums[i + 1]);
            tailInd += nums[i];
        }
        return res;
    }
}
// @lc code=end
