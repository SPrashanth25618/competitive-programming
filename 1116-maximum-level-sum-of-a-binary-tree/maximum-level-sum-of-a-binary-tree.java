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
    public int maxLevelSum(TreeNode root) {
        int maxi_sum = (int) -1e6, lvl = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int idx = 1;
        while (!q.isEmpty()) {
            int size = q.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode f = q.poll();
                sum += f.val;
                if (f.left != null)
                    q.offer(f.left);
                if (f.right != null)
                    q.offer(f.right);
            }
            if (sum > maxi_sum) {
                lvl = idx;
                maxi_sum = sum;
            }
            idx++;
        }        
        return lvl;
    }
}