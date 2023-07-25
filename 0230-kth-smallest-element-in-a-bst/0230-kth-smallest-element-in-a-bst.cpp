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
private :
    int res;
public:
    //This is inorder traversal 
    //so we traverse first left , then root , right after that 
    //in bst left subtree always contains the smallest value in the whole tree
    //so wee go deep and backtrack the levels we came across 
    //in fact we traverse the values in sorted order wise 
    //when we backtrack when we reach the k level from the ground 
    //we gonna have the kth smallest value in our hand 
    
    //time complexity and space complexity of this is O(n) and O(1)
    
    //we gonna use the heap 
    //that gonna become O(n) tc and O(n) sc
    
    //but if we sort by storing the nodes in the vector 
    
    //that gonna give tc and sc of nlogn and n
    
    
    void dfs(TreeNode*root,int& k)
    {
        if(!root)return ;
        
        dfs(root->left,k);
        
        if(--k == 0)res=root->val;
        
        dfs(root->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return res ;
    }
};