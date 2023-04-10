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
    //inorder ->left root right
    //preorder ->root left right
    //postorder ->left right root
    void dfs(TreeNode* root,vector<int>curset,vector<vector<int>>&ans,int ts)
{
       if(root==nullptr) return ;
       
        //after adding the current value we check wether current 
        //node is leaf or not
       curset.push_back(root->val);
        
       if(root->left==nullptr and root->right==nullptr)
       {
           if(accumulate(curset.begin(),curset.end(),0) == ts)
           {
               ans.push_back(curset);
           }
       }
        
        
        
        dfs(root->left,curset,ans,ts);
        dfs(root->right,curset,ans,ts);
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>curset;
        vector<vector<int>>ans;
        dfs(root,curset,ans,targetSum);
        return ans;
    }
};