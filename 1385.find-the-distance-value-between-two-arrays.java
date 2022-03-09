import java.util.Arrays;
import java.util.stream.IntStream;

/*
 * @lc app=leetcode id=1385 lang=java
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

// @lc code=start
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        arr2 = IntStream.of(arr2).sorted().toArray();
        int res = 0;
        for (var n : arr1) {
            int lb_ind = Arrays.binarySearch(arr2, n);
            if (lb_ind < 0) {
                lb_ind = -(lb_ind + 1);
            } else {
                continue;
            }
            if (lb_ind == arr2.length) {
                if (n - arr2[lb_ind - 1] > d) {
                    ++res;
                }
            } else if (lb_ind == 0) {
                if (arr2[0] - n > d) {
                    ++res;
                }
            } else if (arr2[lb_ind] - n > d && n - arr2[lb_ind - 1] > d) {
                ++res;
            }
        }
        return res;
    }
}
// @lc code=end
