/*
 * @lc app=leetcode id=470 lang=java
 *
 * [470] Implement Rand10() Using Rand7()
 */

// @lc code=start
/**
 * The rand7() API is already defined in the parent class SolBase. public int
 * rand7();
 * 
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        int a = rand7(), b = rand7();
        if (b <= 4) {
            return a;
        } else if (a <= 4) {
            return 3 + b;
        } else {
            return rand10();
        }
    }
}
// @lc code=end
