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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        int cnt=0;
        
        while(!q.empty())
        {
            long long len=q.size();
            long long curLevelSum=0;
            while(len--)
            {
                TreeNode* ptr=q.front();
                q.pop();
                curLevelSum+=ptr->val;
                if(ptr->left!=nullptr)q.push(ptr->left);
                if(ptr->right!=nullptr)q.push(ptr->right);
            }
            cnt++;
            pq.push(curLevelSum);
            
            if(pq.size()>k)pq.pop();
        }
        
        return (cnt<k) ?-1:pq.top();
    }
};