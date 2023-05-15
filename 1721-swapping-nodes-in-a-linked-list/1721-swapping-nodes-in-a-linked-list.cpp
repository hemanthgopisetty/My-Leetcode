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
          
          after that move the ptr pointing to the kth node to next node
          and keep a pointer at first node named as endk in such a way we are having a distance between ptr and endk of k
          
          when ptr reaches null then endk ptr will be at kth node form the end of the given linked list
          
          noew two pointer are pointing to the 
            kth node from the beginning ->bnk
            kth node from the end -> endk
            
            qns description was two swap the values
            so swap the values of bnk and endk
            
            that's it 
          
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