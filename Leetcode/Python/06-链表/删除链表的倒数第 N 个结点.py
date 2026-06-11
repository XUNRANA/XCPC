# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
from typing import Optional


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        fast = dummy
        slow = dummy
        for _ in range(n):
            fast = fast.next
        while fast.next:
            fast = fast.next 
            slow = slow.next

        slow.next = slow.next.next
        return dummy.next 
    # def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    #     curr = head
    #     count = 0
    #     while curr:
    #         curr = curr.next
    #         count += 1
    #     count -= n

    #     curr = head
    #     pre = None
    #     while curr:
    #         if count == 0:
    #             if not pre:
    #                 return curr.next
    #             pre.next = curr.next
    #             return head
    #         count -= 1
    #         pre = curr 
    #         curr = curr.next
