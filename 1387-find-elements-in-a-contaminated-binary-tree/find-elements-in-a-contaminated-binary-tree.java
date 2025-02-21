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
class FindElements {
    HashSet<Integer> st;
    public void fillValues(TreeNode root,int num){
        if(root == null )
            return ;
        root.val = num;
        st.add(num);
        fillValues(root.left,2*num+1);
        fillValues(root.right,2*num+2);
    }
    public FindElements(TreeNode root) {
        st = new HashSet<>();
        fillValues(root,0);
    }
    
    public boolean find(int target) {
        return st.contains(target);
        
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */