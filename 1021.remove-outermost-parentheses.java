/*
 * @lc app=leetcode id=1021 lang=java
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
class Solution {
    public String removeOuterParentheses(String s) {
        int count = 0;
        StringBuilder res = new StringBuilder();
        for (var c : s.toCharArray())
        {
            if (c == '(')
            {
                ++count;
                if (count != 1)
                {
                    res.append(c);
                }
            }
            else
            {
                --count;
                if (count != 0)
                {
                    res.append(c);
                }
            }
        }
        return res.toString();
    }
}
// @lc code=end

