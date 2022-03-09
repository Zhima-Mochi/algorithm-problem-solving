import java.util.Arrays;

/*
 * @lc app=leetcode id=1365 lang=java
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        Integer[] sorted_arr = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(sorted_arr);
        for (int i = 0; i != nums.length; ++i) {
            nums[i] = lower_bound(sorted_arr, nums[i]);
        }
        return nums;
    }

    int lower_bound(Integer[] arr, int key) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
// @lc code=end
