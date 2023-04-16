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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)return {} ;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty())
        {
            TreeNode* focusednode;
            vector<int> f;
            int len=q.size();
            for(auto i=0;i<len;i++)
            {
                focusednode=q.front();
                q.pop();
                f.push_back(focusednode->val);
                
            if(focusednode->left != nullptr)
            {
                q.push(focusednode->left);
            }
            
            if(focusednode->right != nullptr)
            {
                q.push(focusednode->right);
            }
                
          }
           ans.push_back(f);
        }
        return ans;
    }
};