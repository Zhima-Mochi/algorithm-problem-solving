import java.util.Arrays;

/*
 * @lc app=leetcode id=475 lang=java
 *
 * [475] Heaters
 */

// @lc code=start
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int res = 0;
        for (var h : houses) {
            int index = Arrays.binarySearch(heaters, h);
            if (index < 0) {
                int right_heater_ind = -(index + 1);
                int right_heater = right_heater_ind == heaters.length ? Integer.MAX_VALUE : heaters[right_heater_ind];
                if (right_heater - h <= res) {
                    continue;
                } else if (right_heater_ind == 0) {
                    res = right_heater - h;
                    continue;
                }
                int left_heater = heaters[right_heater_ind - 1];
                if (h - left_heater <= res) {
                    continue;
                }
                res = Math.min(h - left_heater, right_heater - h);
            }
        }
        return res;
    }
}
// @lc code=end
