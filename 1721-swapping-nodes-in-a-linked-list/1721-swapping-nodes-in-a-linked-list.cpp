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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        /*
          bnk = beginning k th node
          endk =from the end kth node
          
          Intially we will  traverse upto kth node via ptr 
          After reaching th kth node , we will keep one ptr as a reference named as bnk
          after keeping the bnk at the kth node we have now two pointer's pointing to 
          k th node
          
        */
        ListNode *ptr=head,*endk=head,*bnk=nullptr;
        for(auto i=1;i<k;i++)
           ptr=ptr->next;
        
        bnk=ptr;
        ptr=ptr->next;
        while(ptr)
        {
            ptr=ptr->next;
            endk=endk->next;
        }
        
        swap(bnk->val,endk->val);
        return head;
    }
};