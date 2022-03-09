import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @lc app=leetcode id=508 lang=java
 *
 * [508] Most Frequent Subtree Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    // public class TreeNode {
    //     int val;
    //     TreeNode left;
    //     TreeNode right;

    //     TreeNode() {
    //     }

    //     TreeNode(int val) {
    //         this.val = val;
    //     }

    //     TreeNode(int val, TreeNode left, TreeNode right) {
    //         this.val = val;
    //         this.left = left;
    //         this.right = right;
    //     }
    // }

    public int max_freq = 0;

    public int[] findFrequentTreeSum(TreeNode root) {
        Map<Integer, Integer> umap = new HashMap<>();
        postOrder(root, umap);
        List<Integer> res = new ArrayList<>();
        for (var p : umap.entrySet()) {
            if (p.getValue() == max_freq) {
                res.add(p.getKey());
            }
        }
        return res.stream().mapToInt(i -> i).toArray();
    }

    int postOrder(TreeNode root, Map<Integer, Integer> umap) {
        if (root == null) {
            return 0;
        }
        int sum_val = root.val + postOrder(root.left, umap) + postOrder(root.right, umap);
        umap.put(sum_val, umap.getOrDefault(sum_val, 0) + 1);
        max_freq = Math.max(max_freq, umap.get(sum_val));
        return sum_val;

    }
}
// @lc code=end
