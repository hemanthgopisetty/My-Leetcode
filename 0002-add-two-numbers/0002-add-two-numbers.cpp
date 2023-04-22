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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp=ans;
        
        int carry=0;
        while(l1!=nullptr or l2!=nullptr or carry)
        {
            int sum=0;
            
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            
            ListNode* newnode = new ListNode(sum%10);
            carry=sum/10;//0 or 1 mostly
            temp->next=newnode;
            temp=temp->next;
        }
        
        //y ? becuase head is stored in the next pointer of ans 
        //usually we need to write like if res=null then add the first node
        //maintain the two prevnode and temp pointing to current
        //this simplifies the process
        return ans->next;
        
    }
};