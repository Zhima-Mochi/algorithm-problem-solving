import java.util.ArrayList;
import java.util.stream.IntStream;

/*
 * @lc app=leetcode id=1403 lang=java
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

// @lc code=start
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        int sum_val = IntStream.of(nums).sum();
        int[] count_sort = new int[101];
        for (var n : nums) {
            ++count_sort[n];
        }
        int count = 0;
        List<Integer> res = new ArrayList<>();
        for (int i = 100; i != 0; --i) {
            while (count_sort[i] > 0 && count <= sum_val / 2) {
                res.add(i);
                count += i;
                --count_sort[i];
            }
            if (count > sum_val / 2) {
                break;
            }
        }
        return res;
    }
}
// @lc code=end
