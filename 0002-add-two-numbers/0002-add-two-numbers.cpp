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
        //Aim we have to return List 
        //Where the list contains the result of the two list node
        //There is no constraint on the lenght of the list
        //Lists length can be small or big or equal
        //we have to traverse upto any of the big list become null
        //We have to make the Node for the Carry's value tooo
        //O(max(l1.size(),l2.size()));
        ListNode* ans=new ListNode(); 
         ListNode* temp=ans;
        int carry=0;
        while(l1!=nullptr or l2!=nullptr || carry)
        {
            int sum=0;
            if(l1 !=nullptr)
            {
                sum+=l1->val;
                l1=l1->next;
            }
             if(l2 !=nullptr)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            ListNode* newnode=new ListNode(sum%10);
            carry=sum/10;
            temp->next=newnode;
            temp=temp->next;
        }
        return ans->next;
    }
};