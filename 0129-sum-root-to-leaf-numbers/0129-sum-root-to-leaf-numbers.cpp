
class Solution {
public:
    /*•	Approach:
o	As question say’s we have to traverse upto the leaf node in right and left
o	If we observe the second example ,we have to traverse upto the leaf node and after going to the next path we  have to remember the sum we made upto to that node 
	For example, 495, and 491 if we carefully observe
 
o	We are going to use the DEPTH-FIRST SEARCH approach
o	We’ll traverse to the end
	While traversing we change the node’s value
 */
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    int dfs(TreeNode* root,int cur){
        if(!root)return 0;//if it's null then return 0;
        cur=cur*10+root->val;//for future reference create curretn variable;
        if(!root->left and !root->right) return cur;//if root left or root->right 
        return dfs(root->left,cur)+dfs(root->right,cur);
    }
};