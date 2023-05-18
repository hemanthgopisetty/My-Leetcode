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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* curnode=nullptr;
            int len=q.size();
            while(len--)
            {
                curnode=q.front();
                q.pop();
                if(curnode->left)q.push(curnode->left);
                
                if(curnode->right)q.push(curnode->right);
            }
            ans.push_back(curnode->val);
        }
        return ans;
    }
};