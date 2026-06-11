# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
from typing import Optional


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:


        dummy = ListNode(-1, head)
        pre = dummy
        while pre.next and pre.next.next:
            node1 = pre.next
            node2 = pre.next.next

            pre.next = node2
            node1.next = node2.next
            node2.next = node1
            
            pre = node1
        return dummy.next
       