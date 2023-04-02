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
    void dfs(TreeNode* root,string s,vector<string>&a)
    {
        //visit,left,right->preorder;
        s+=to_string(root->val);
        //root condition
        if(root->left==nullptr and root->right == nullptr)
        {
            a.push_back(s);
            return ;
        }
        //if left subtree there then traverse
        if(root->left)
        {
            //in left go deep left
            dfs(root->left,s+"->",a);
        }
        //if left there , thren traverse right too 
        if(root->right)
        {
            //in left traversal go right after left subtree over
            //if left subtree over go to right subtree
            //in right subtree
            //traverse left and go right
            dfs(root->right,s+"->",a);
        }
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>a;
        string temp="";
        dfs(root,temp,a);
        return a;
    }
};