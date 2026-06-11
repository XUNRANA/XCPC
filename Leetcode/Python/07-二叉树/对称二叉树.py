# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def check(left, right):
            if not left and not right:
                return True
            if not left or not right:
                return False
            return check(left.left, right.right) and check(left.right, right.left) and left.val == right.val
        return check(root.left, root.eight) if root else True