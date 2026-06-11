# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
from typing import Optional


class Solution:
    # def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    #     if not list1:
    #         return list2
    #     if not list2:
    #         return list1
    #     head = tail = None
    #     while list1 and list2:
    #         if list1.val < list2.val:
    #             if head == None:
    #                 head = tail = list1
    #             else:
    #                 tail.next = list1
    #                 tail = tail.next
    #             list1 = list1.next
    #         else:
    #             if head == None:
    #                 head = tail = list2
    #             else:
    #                 tail.next = list2
    #                 tail = tail.next
    #             list2 = list2.next
    #     if list1:
    #         tail.next = list1
    #     if list2:
    #         tail.next = list2
    #     return head    
    
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
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
