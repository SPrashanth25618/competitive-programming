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
    int m = (int)1e9+7;
    long totsum;
    long ans;
    public int maxProduct(TreeNode root) {        
        totsum = gettotal(root);
        ans = (long)0;
        fun(root);
        return (int)(ans%m);
    }
    public long fun(TreeNode root){
        if(root == null)
            return 0;
        long l = fun(root.left);
        long r = fun(root.right);
        long cursum = l+r+root.val;        
        ans = Math.max(ans,(long)cursum*(totsum-cursum));        
        return cursum;
    }
    public long gettotal(TreeNode root){
        if(root == null)
            return 0;
        long l = gettotal(root.left);
        long r = gettotal(root.right);
        return ((l+r)+root.val);
    }
}