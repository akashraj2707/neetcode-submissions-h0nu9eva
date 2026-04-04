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

public class NodePair{
    public TreeNode node;
    public int level;

    public NodePair(TreeNode node,int level){
        this.node = node;
        this.level = level;
    }
}
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root==null)
            return res;
        Queue<NodePair> q = new ArrayDeque<>();

        q.offer(new NodePair(root ,0) );
        NodePair temp;
        int level;
        TreeNode node;
        int currLevel = 0;
        List<Integer> entry = new ArrayList<>();
        while(q.size()>0){
            temp = q.poll();
            node = temp.node;
            level = temp.level;
            if(level != currLevel){
                res.add(entry);
                entry = new ArrayList<>();
                currLevel = level;
            }    

            // System.out.println(level);
            entry.add(node.val);

            if(node.left != null){
                q.offer(new NodePair(node.left,level+1));
            }

            if(node.right != null){
                 q.offer(new NodePair(node.right,level+1));
            }
           
        }

        res.add(entry);

        return res;
    }
}
