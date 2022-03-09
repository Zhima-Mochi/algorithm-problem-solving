import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=437 lang=java
 *
 * [437] Path Sum III
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    Map<Integer, Integer> past_sum = new HashMap<>() {
        {
            put(0, 1);
        }
    };
    int res = 0;

    public int pathSum(TreeNode root, int targetSum) {
        preorderTras(root, targetSum, 0);
        return res;
    }

    public void preorderTras(TreeNode root, final int targetSum, int current_sum) {
        if (root == null) {
            return;
        }
        current_sum += root.val;
        if (past_sum.containsKey(current_sum - targetSum)) {
            res += past_sum.get(current_sum - targetSum);
        }
        past_sum.put(current_sum, past_sum.getOrDefault(current_sum, 0) + 1);
        preorderTras(root.left, targetSum, current_sum);
        preorderTras(root.right, targetSum, current_sum);
        past_sum.put(current_sum, past_sum.get(current_sum) - 1);
    }
}
// @lc code=end
