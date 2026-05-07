/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    int res;
    public int helper(TreeNode root){
        if(root == null)
            return 0;

        int left = helper(root.left);
        int right = helper(root.right);
        
        left = (left > 0) ? left : 0;
        right = (right > 0) ? right : 0; 
        res = Math.max(res, root.val + left + right);

        return root.val + Math.max(left, right);
    }
    public int maxPathSum(TreeNode root) {
        
        res =root.val;
        helper(root);
        return res;
    }
}
