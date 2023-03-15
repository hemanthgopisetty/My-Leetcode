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
/*
Same as same tree
Creating implict stack of fn elements where they do some work and create 2 fn calls each time until the first element gets poped out by closing brace of that fn call element
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return dfs(root->left,root->right);
    }
    bool dfs(TreeNode*l,TreeNode*r)
    {
        if(l==nullptr or r==nullptr)return l==r;
        
        return(l->val==r->val and dfs(l->left,r->right) and dfs(l->right,r->left));
    }
};