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
    //inorder -> left,root,right
    //preorder ->root,left,right
    //postorder ->left,right,root
    bool inorder(TreeNode* root,int x,int s)
    {
        //if root is nullptr return false ;
        if(!root) return false ;
        
        //if root is leaf node i.e(left and right is nullptr) then
        //add the current value and check whether they both are equal or not
        if( !root->left and !root->right )
        {
            //add current root value 
            x=x+root->val;
            if(x==s)//true
            {
                //then
                return true ;
            }
        }
        
        //given sum may be in left subtree or right subtree 
        //if any of the given subtree give true then
        //there is required sum
        
        return inorder(root->left,x+root->val,s) or inorder(root->right,x+root->val,s);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        
        return inorder(root,0,sum);
    }
};