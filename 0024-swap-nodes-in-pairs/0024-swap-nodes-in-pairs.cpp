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
   
    ListNode* sol(ListNode* head)
    {
        ListNode* dummy = new ListNode();
        ListNode* cur=head;
        ListNode* prev=dummy;
        
        while(cur and cur->next)
        {
            prev->next=cur->next;//2
            cur->next=prev->next->next;//1->next=2->next->next(3) ==> prev->next->next
            prev->next->next=cur;//2->next points to 1 
            prev=cur;
            cur=cur->next;
        }
        return dummy->next;
    }
    ListNode* swapPairs(ListNode* head) {
        //base  cases 
        if(!head or !head->next)return head;
        return sol(head);
    }
};