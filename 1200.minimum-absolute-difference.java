import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=1200 lang=java
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        int min_val = Integer.MAX_VALUE;
        int len = arr.length;
        for (int i = 1; i != len; ++i) {
            if (arr[i] - arr[i - 1] < min_val) {
                min_val = arr[i] - arr[i - 1];
            }
        }
        for (int i = 1; i != len; ++i) {
            if (arr[i] - arr[i - 1] == min_val) {
                result.add(Arrays.asList(arr[i - 1], arr[i]));
            }
        }
        return result;
    }
}
// @lc code=end
