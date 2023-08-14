/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
* Iterative  => reverse the list
*               traverse the reversed list
*               by carraying a carry
*               and again reverse the new linked list 
*

* Recursive  => Single call (o to n) Non Tail Recursion
*               Using NT recursion to eliminate reverse function 
*               as we return carry in every NT recursion
*/
class Solution {
public:
    //retrun carry
    int recurs(ListNode*cur)
    {
     
        //recurs until no nodes are there
        
        if(!cur)return 0;
        
        //Non tail recursion
        int carry =cur->val*2 + recurs(cur->next);
        
        //replace value
        cur->val = carry%10;
        
        //return carry
        
        return carry/10;
        
    }
    ListNode* doubleIt(ListNode* head) {
        
        //there may have chance of remaining extra carry
        int carry = recurs(head);
        
        if(carry) head = new ListNode(carry,head);
        
        return head;
        
    }
};