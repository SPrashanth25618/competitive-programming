/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructBinaryTree(string &traversal,int& i,int& n,int dep){
        if(i >= n)
            return nullptr;
        int j = i;
        while(j<n && traversal[j] == '-'){
            j++;
        }
        int dashes = j-i;
        if(dashes != dep)
            return nullptr;
        i += dashes;
        int num = 0;
        while(i<n && isdigit(traversal[i])){
            num = num*10 + (traversal[i] - '0');
            i++;
        }
        TreeNode* node = new TreeNode(num);
        node->left = constructBinaryTree(traversal,i,n,dep+1);
        node->right = constructBinaryTree(traversal,i,n,dep+1);
        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0;
        int n = traversal.length();
        return constructBinaryTree(traversal,i,n,0);
    }
};