import java.util.Stack;

/*
 * @lc app=leetcode id=1475 lang=java
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution {
    public int[] finalPrices(int[] prices) {
        Stack<Integer> st = new Stack<>();
        int width = prices.length;
        for (int i = 0; i != width; ++i) {
            while (!st.empty() && prices[st.peek()] >= prices[i]) {
                prices[st.peek()] -= prices[i];
                st.pop();
            }
            st.add(i);
        }
        return prices;
    }
}
// @lc code=end
