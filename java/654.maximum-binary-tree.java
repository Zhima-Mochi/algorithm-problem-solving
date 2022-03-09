/*
 * @lc app=leetcode id=654 lang=java
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */

// T:O(N log N) S:O(1)
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        TreeNode root = new TreeNode(nums[0]);
        int width = nums.length;
        for (int i = 1; i != width; ++i) {
            if (nums[i] > root.val) {
                root = new TreeNode(nums[i], root, null);
            } else {
                TreeNode cur = root;
                while (cur.right != null && nums[i] < cur.right.val) {
                    cur = cur.right;
                }
                cur.right = new TreeNode(nums[i], cur.right, null);
            }
        }
        return root;
    }
}
// @lc code=end
