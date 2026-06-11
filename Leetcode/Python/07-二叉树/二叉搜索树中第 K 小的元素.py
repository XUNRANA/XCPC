# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # left mid right
        l = []
        def midorder(node):
            if node.left:
                midorder(node.left)
            l.append(node.val)
            if node.right:
                midorder(node.right)

        midorder(root)
        return l[k-1]