import java.util.ArrayList;
import java.util.List;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=538 lang=java
 *
 * [538] Convert BST to Greater Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public TreeNode convertBST(TreeNode root) {
        List<TreeNode> st = new ArrayList<>();
        var cur = root;
        int accum_val = 0;
        while (true) {
            if (cur != null) {
                st.add(cur);
                cur = cur.right;
            } else if (!st.isEmpty()) {
                var last_elem = st.remove(st.size() - 1);
                accum_val = last_elem.val += accum_val;
                cur = last_elem.left;
            } else {
                break;
            }
        }
        return root;
    }
}
// @lc code=end
