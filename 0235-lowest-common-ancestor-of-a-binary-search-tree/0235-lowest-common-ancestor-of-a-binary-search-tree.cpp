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
            ==> here we need to use the bst characterstics
            ==> root->left <root->value < root->right 
            
        */
        
        //if root value is greater than the p and q values then we will search in the left subree
        if((root->val > p->val) and (root->val > q->val))
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        
        //if root value is lesser than the p and q values then we will search in the right subtree
        if((root->val < p->val) and (root->val < q->val))
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        
        return root ;
    }
};