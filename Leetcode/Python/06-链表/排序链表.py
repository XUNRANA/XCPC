# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
from typing import Optional


class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        slow_pre = None
        slow = head
        fast = head
        while fast and fast.next:
            slow_pre = slow
            slow = slow.next
            fast = fast.next.next
        slow_pre.next = None

        left = self.sortList(head)
        right = self.sortList(slow)
        return self.merge(left, right)
    def merge(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = tail = ListNode(-1)
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        tail.next = list1 if not list2 else list2
        return dummy.next
