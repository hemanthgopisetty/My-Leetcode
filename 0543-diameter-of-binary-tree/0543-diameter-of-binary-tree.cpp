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
    /*
      => Given the root of a binary tree, return the length of the diameter of the tree.
      => The diameter of a binary tee is the longest path between any two nodes in a ree 
      => This path may or may not pass through the root
    */
    
    Solution()
    {
        ans=0;
    }
    
    int dfs(TreeNode*root)
    {
        if(root == nullptr)return 0;
        
        //calculate the depth  on left and right 
        int left  = dfs(root->left);
        int right = dfs(root->right);
        
        //calculating depth from every node 
        ans = max(ans,1+left+right);
        
        //return the max of left or right side 
        return 1+max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(not root)return 0;
        
        dfs(root);
        
        return ans-1;
    }
private :
    int ans ;
};