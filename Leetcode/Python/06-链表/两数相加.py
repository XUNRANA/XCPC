# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
from typing import Optional


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = 0
        k = 1
        while l1:
            num1 += k * l1.val
            k *= 10
            l1 = l1.next
        
        num2 = 0
        k = 1
        while l2:
            num2 += k * l2.val
            k *= 10
            l2 = l2.next

        num = num1 + num2
        if num == 0:
            return ListNode(0)
        dummy = tail = ListNode(-1)
        while num:
            x = num % 10
            num //= 10
            tail.next = ListNode(x)
            tail = tail.next
        return dummy.next