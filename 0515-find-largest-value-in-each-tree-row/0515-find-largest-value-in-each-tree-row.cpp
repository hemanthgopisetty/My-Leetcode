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
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int>ans;
        while(!q.empty())
        {
            int len = q.size();
            int large = INT_MIN;
            for(int i=0;i<len;i++)
            {
                 TreeNode* temp = q.front();
                 q.pop();
                 large = max(temp->val,large);
                if(temp->left!= nullptr)q.push(temp->left);
                if(temp->right!= nullptr)q.push(temp->right);
            }
            ans.push_back(large);
            large = INT_MIN;
        }
        return ans;
    }
};