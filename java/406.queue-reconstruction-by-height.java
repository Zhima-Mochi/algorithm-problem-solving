import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode id=406 lang=java
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start

class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (l, r) -> (l[0] == r[0] ? l[1] - r[1] : r[0] - l[0]));
        List<int[]> res = new LinkedList<>();
        for (int[] arr : people) {
            res.add(arr[1], arr);
        }
        return res.toArray(new int[people.length][]);
    }
}
// @lc code=end
