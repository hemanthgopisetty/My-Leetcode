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
/*Instructing the computer
Instructions : Rescursions
    Pseudo code :
        create a implict stack with function object as a parameter
            In that function call
                do this :
                    Every element in the stack do this :
                          1.CHECK IF ONE OF THE TWO GIVEN NODES ARE EQUAL IF (LEAF NODE) ~RETURN THERE EQUALITY
                          2.IF VALUES OF GIVEN TRESS ON SAME SIDE ARE EQUAL THEN CREATE TWO FUNCTION CALL ELMENTSS THAT DO CHECK LEFT OF BOTH TREES AND RIGHT OF BOTH TREE
                          IF THESE THREE RETURN TRUE ->THEN BOTH ARE SAME TREE
                          ELSE BOTH ARE SAME FALSE
NOTE IN THIS STACK EVERY ELEMENT WILL CREATE TWO STACK ELEMENTS WHERE THAT IS THE PART OF OUR SOLUTION
                    
        
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p==nullptr or q==nullptr) return p==q;
         return ((p->val == q->val) and isSameTree(p->left,q->left) and isSameTree(p->right,q->right)) ;
    }
};