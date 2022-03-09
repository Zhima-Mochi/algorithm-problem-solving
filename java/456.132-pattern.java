import java.util.Stack;

/*
 * @lc app=leetcode id=456 lang=java
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution {
    public boolean find132pattern(int[] nums) {
        Stack<Integer> st = new Stack<>();
        int len = nums.length;
        int third = Integer.MIN_VALUE;
        for (int i = len - 1; i >= 0; --i) {
            if (nums[i] < third) {
                return true;
            }
            while (!st.empty() && nums[i] > st.peek()) {
                third = st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
}
// @lc code=end
