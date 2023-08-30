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
    void reorderList(ListNode* head) {
        //if there is single node then return        
        if(!head->next)return ;
        
        //middle of the linked list
        ListNode *slow=head,*fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //reverse the linked list from the middle (slow)
        ListNode*prev=nullptr,*cur=slow->next;
        slow->next=nullptr;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        //join the mid half and first half according the question
        ListNode*mid=prev,*fir=head;
        while(mid!=nullptr and fir!=nullptr)
        {
            ListNode*fnext=fir->next;
            ListNode*mnext=mid->next;
            
            fir->next=mid;
            mid->next=fnext;
            
            fir=fnext;
            mid=mnext;
        }
    }
};