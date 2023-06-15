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

//return the maximum sun with smallest level
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int ans=-1;
        int maxSum = INT_MIN;
        
        while(!q.empty())
        {
            
            int len=q.size();
            int curSum=0;
            
            //increase the level ,when are u at the current level
            level++;
            //finding the sum at the current level
            while(len--)
            {
                TreeNode* ptr=q.front();
                q.pop();
                curSum+=ptr->val;
                if(ptr->left!=nullptr)
                {
                    q.push(ptr->left);
                }
                
                if(ptr->right!=nullptr)
                {
                    q.push(ptr->right);
                }
            }
            
            //if curSum maxsum change level;
            if(curSum>maxSum)
            {
                maxSum=curSum;
                ans=level;
            }
        }
        return ans;
    }
};