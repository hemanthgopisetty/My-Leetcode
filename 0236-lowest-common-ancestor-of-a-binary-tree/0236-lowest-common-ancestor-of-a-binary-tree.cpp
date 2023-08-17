/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        /*
        => root left right -> Preorder Traversal
        
        => If left subtree contains one of descendant (p or q) and right subtree contains the remaining descendant (q or p) then the root is their LCA.
        
        => If left subtree contains both p and q then return left as their LCA.
        
        => If right subtree contains both p and q then return right as their LCA.
        
        */
        
        if(root==nullptr or root == p or root ==q) return root ;
        
        TreeNode* left  = lowestCommonAncestor(root->left,p,q);
        
        TreeNode* right  = lowestCommonAncestor(root->right,p,q);
        
        
        if(left!=nullptr and right!=nullptr)return root;
        if(left!=nullptr)return left;
        return right ;
        
    }
};