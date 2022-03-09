import java.util.Stack;

/*
 * @lc app=leetcode id=224 lang=java
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
    public int calculate(String s) {
        Stack<Byte> sign_st = new Stack<>();
        sign_st.push((byte) 1);
        byte sign = 1;
        int val = 0;
        int res = 0;
        for (var c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                val *= 10;
                val += c - '0';
            } else if (c == '+' || c == '-') {
                res += sign * val;
                val = 0;
                sign = c == '+' ? sign_st.peek() : (byte) -sign_st.peek();
            } else if (c == '(') {
                sign_st.push(sign);
            } else if (c == ')') {
                // res += sign * val;
                sign_st.pop();
            }
        }
        return res + sign * val;
    }
}
// @lc code=end