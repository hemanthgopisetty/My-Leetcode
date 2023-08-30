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
        
        //make null to last node of first_half list; 
        slow->next=nullptr;
        
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        //join the mid_half and first_half according the question
        ListNode*mid_half=prev,*first_half=head;
        while(mid_half!=nullptr and first_half!=nullptr)
        {
            //storing all two half's next 
            ListNode*fnext=first_half->next;
            ListNode*mnext=mid_half->next;
            
            //point first_half current node->next to the mid_half current node
            first_half->next=mid_half;
            //point mid_half current_node->next to the fnext(first_half current node ->next)
            mid_half->next=fnext;
            
            //move current node the stored next's
            first_half=fnext;
            mid_half=mnext;
        }
    }
};