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
    TreeNode* construct(string &s,int &i,int &n,int depth)
    {
        if(i >= n)
            return nullptr;
        int j = i;
        while(j<n && s[j] == '-')
            j++;
        int dashes = j-i;
        if(dashes != depth)
            return nullptr;
        i = j;
        int val = 0;
        while(i<n && isdigit(s[i])){
            val = val*10 + (s[i] - '0');
            i++;
        }
        TreeNode* node = new TreeNode(val);
        node->left = construct(s,i,n,depth+1);
        node->right = construct(s,i,n,depth+1);
        return node;
    }
    TreeNode* recoverFromPreorder(string s) {
       int n = s.size(),i = 0;
       return construct(s,i,n,0) ;
    }
};