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
indorder-> left,root,right
preorder->root,left,right
postorder->left,right,root
*/
/*
determine if it is a valid binary tree

"left subtree" of a "node contains" "only nodes with keys less" "than the node's key
"

"right subtree" of a "node contains " "only nodes with keys greater" "than the node's key"

Example :-   (2)
            /   \       => valid binary tree
           (1)  (3)
*/
class Solution {
public:
    vector<int>a;
     void inorder(TreeNode* root)
    {
       if(root==nullptr)
       {
           return ;
       }
        
       inorder(root->left);//if base case passes exectuon goes to next line
        //this line is executed after this fn call got hit by base case
       a.push_back(root->val);
        //this line is executed after push back the current element
       inorder(root->right);//if base case passes execution go to next line,call left(same like left call) and pb the element and call again the right 
      //this line is executed after above work is done
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(auto i=0;i<a.size()-1;i++)
        {
            if(a[i+1] <= a[i]) 
            {
                return false ;
            }
        }
        return true;
        
    }
    
   
};