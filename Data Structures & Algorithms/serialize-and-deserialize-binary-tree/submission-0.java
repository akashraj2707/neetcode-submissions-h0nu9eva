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

public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        // [1 -> [2,3]] - [2 -> [4,5]]
        if(root==null)
            return "";
        Queue<TreeNode> q = new ArrayDeque<>();
        String s = "" + root.val;

        q.offer(root);

        while(q.size() > 0){
            TreeNode node = q.poll();

            
            if(node.left != null){
                s = s + "," + node.left.val;
                q.offer(node.left);
            }else s = s + "," + "X";

            if(node.right != null){
                s = s + "," + node.right.val;
                q.offer(node.right);
            }else s = s + "," + "X";
        }

        return s;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        System.out.println(data);

        if(data.length()==0)
            return null;

        String[] arr = data.split(",");

        Queue<TreeNode> q = new ArrayDeque<>();

        
        int ind=1;
        TreeNode res = new TreeNode( Integer.valueOf(arr[0]));
        q.offer(res);
        while(q.size()>0){
            TreeNode node = q.poll();
            TreeNode left = null;
            TreeNode right = null;    
            if( !arr[ind].equals("X")){
               
               left = new TreeNode(Integer.valueOf(arr[ind]));   
               q.offer(left);  
            }
            ind ++;

            if( !arr[ind].equals("X")){
               right = new TreeNode(Integer.valueOf(arr[ind]));     
               q.offer(right);
            }
            ind++;

            node.left = left;
            node.right = right;
        }

        
        return res;
    }
}
