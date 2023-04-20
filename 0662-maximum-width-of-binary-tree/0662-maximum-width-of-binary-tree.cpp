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
In every level we need to calcualte the widht 
after calculating the all the level's width just return the maximum dude ~!

*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;//FIFO BACK ->RECENTLY PUSEHD FRONT ->PUSHED AT FIRST 
        int res =0;
        
        q.push({root,0});
        
        while(!q.empty())
        {
          int len=q.size();
          int start_node = q.front().second;//first node entered in the queue is the one poped from the queue
          int last_node = q.back().second;//last node entered in the queue is the one pushed to the queue
          
            res=max(res,last_node-start_node+1);
           
            for(auto i=0;i<len;i++)
            {
                auto x=q.front();
                int idx=x.second-start_node;
                q.pop();
                if(x.first->left!=nullptr)
                {
                    q.push({x.first->left,2ll*idx+1});
                }
                if(x.first->right!=nullptr)
                {
                    q.push({x.first->right,2ll*idx+2});
                }
            }
        }
        return res ;
    }
};