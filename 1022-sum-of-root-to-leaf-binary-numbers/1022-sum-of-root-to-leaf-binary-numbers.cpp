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
DFS => ROOT LEFT RIGHT and Maintain a array of strings and convert the string to sum  when we traverse the whole tree  1......1000 => 2^50 levels

On worst case => string size = 50 
              => traversing the string O(50)
              => at 50 th level where leaf nodes exist 
              => we will traverse the string and convert it to the number 
              => SC  => string size 50 which means 50 bits+O(n^2)
              => TC  => height of the tree
              => why we are going with this approach is 
              => we need to convert the binaray rep to decimal rep
              => to do so we need to traverse from right to left 
              => suppose 101 
              => from right to left 2^0*1+2^1*0+2^2*1 = 1+0+4 => 5
              We need to optimise such that TC => height of the tree, SC => Should be O(1)
              => we can do that such optimization if we can traverse from left to right
              =>which means we need to mainatian a global variable 
              => whenever we visit leaf we need to add that array og bits to the global
              => variable ans

*/
class Solution {
public:
    int dfs(TreeNode*root,int sum)
    {
        if(!root)
        {
            return 0;
        }
        
        sum = (2*sum)+root->val;
        
        //if it's leaf return the sum 
        if(!root->left and !root->right)return sum;
        
        //else make tree recusrion 
        return dfs(root->left,sum)+dfs(root->right,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        
        return dfs(root,0);
    }
};