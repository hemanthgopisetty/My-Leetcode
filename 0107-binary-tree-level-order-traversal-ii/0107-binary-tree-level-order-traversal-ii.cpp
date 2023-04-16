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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        
        q.push(root);
        
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            TreeNode* focusedNode;
            
            vector<int>f;
            
            int len = q.size();
            
            while(len--)
            {
                focusedNode = q.front();
                
                q.pop();
                
                f.push_back(focusedNode->val);
                
                if(focusedNode->left) q.push(focusedNode->left);
                
                if(focusedNode->right) q.push(focusedNode->right);
                
            }
            
            ans.push_back(f);
            
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};