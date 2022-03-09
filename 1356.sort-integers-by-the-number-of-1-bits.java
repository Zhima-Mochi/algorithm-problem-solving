import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode id=1356 lang=java
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] arrInt = new Integer[arr.length];
        for (int i = 0; i < arr.length; ++i) {
            arrInt[i] = arr[i];
        }
        Arrays.sort(arrInt, Comparator.comparing(i -> Integer.bitCount(i) * (1 << 15) + i));
        for (int i = 0; i < arr.length; ++i)
            arr[i] = arrInt[i];
        return arr;
    }
}
// @lc code=end
