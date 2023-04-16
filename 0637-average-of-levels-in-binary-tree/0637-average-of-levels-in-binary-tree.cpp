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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q ;
        vector<double>ans;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* fn;
            int len=q.size();
            double temp=0.0f;
            for(auto i=0;i<len;i++)
            {
                fn=q.front();
                q.pop();
                temp+=(fn->val);
                if(fn->left)q.push(fn->left);
                if(fn->right)q.push(fn->right);
            }
            ans.push_back((double)temp/len);
        }
        return ans;
    }
};