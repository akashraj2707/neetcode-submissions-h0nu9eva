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

    public int dfs(TreeNode root,int maxSoFar){
        if(root==null)
            return 0;
        int res=0;
        if(root.val >= maxSoFar)
            res++;

        maxSoFar = Math.max(maxSoFar,root.val);
        if(root.left!=null)
            res += dfs(root.left,maxSoFar);
        if(root.right!=null)
            res += dfs(root.right,maxSoFar);

        return res;    

    }
    public int goodNodes(TreeNode root) {
        return dfs(root,-105);
    }
}
