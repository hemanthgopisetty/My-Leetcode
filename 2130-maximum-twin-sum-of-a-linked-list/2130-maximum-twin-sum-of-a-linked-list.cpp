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
    int pairSum(ListNode* head) {
        /*
        ListNode* slow=head,*fast=head;
        while(fast and fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*prev=nullptr,*nextnode;
        while(slow)
        {
            nextnode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextnode;
        }
        int maxval=0;
        while(prev)
        {
            maxval=max(maxval,head->val+prev->val);
            prev=prev->next;
            head=head->next;
        }
        return maxval;
        */
        int maxval=0;
        stack<int>st;
        ListNode *slow,*fast;
        slow=head,fast=head;
        while(fast and fast->next)
        {
            fast=fast->next->next;
            st.push(slow->val);
            slow=slow->next;
        }
        while(slow)
        {
            maxval=max(maxval,st.top()+slow->val);
            st.pop();
            slow=slow->next;
        }
        return maxval;
    }
};