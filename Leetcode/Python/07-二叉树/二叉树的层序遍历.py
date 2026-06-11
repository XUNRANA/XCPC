# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        node = [root]
        ans = []
        while len(node):
            res = []
            new_node = []
            for root in node:
                res.append(root.val)
                if root.left: 
                    new_node.append(root.left)
                if root.right: 
                    new_node.append(root.right)
            node = new_node
            ans.append(res)
        return ans
