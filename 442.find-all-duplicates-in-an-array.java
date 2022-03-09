import java.util.ArrayList;

/*
 * @lc app=leetcode id=442 lang=java
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (var n : nums) {
            var pos = Math.abs(n) - 1;
            if (nums[pos] > 0) {
                nums[pos] *= -1;
            } else {
                res.add(pos + 1);
            }
        }
        return res;
    }
}
// @lc code=end
