# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        """
        slow,fast=head,head
        while fast and fast.next:
            fast=fast.next.next
            slow=slow.next
        
        cur,prev=slow,None
        while cur :
            cur.next,prev,cur=prev,cur,cur.next
        
        ans=0
        while prev:
            ans=max(ans,head.val+prev.val)
            prev,head=prev.next,head.next
        
        return ans
        """
        slow,fast,stack,maxval=head,head,[],0
        
        while fast and fast.next:
            fast=fast.next.next
            stack.append(slow.val)
            slow=slow.next
            
            
        while slow:
            maxval=max(maxval,stack.pop()+slow.val)
            slow=slow.next
            
            
        return maxval
        
            
            
        