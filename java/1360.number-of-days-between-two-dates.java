/*
 * @lc app=leetcode id=1360 lang=java
 *
 * [1360] Number of Days Between Two Dates
 */

// @lc code=start
import java.time.LocalDate;

class Solution {
    public int daysBetweenDates(String date1, String date2) {
        return (int) Math.abs(LocalDate.parse(date1).toEpochDay() - LocalDate.parse(date2).toEpochDay());
    }
}
// @lc code=end
