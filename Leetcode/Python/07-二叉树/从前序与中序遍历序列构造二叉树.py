# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # 根 左 右
        # 左 根 右
        # preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        def dfs(i, l, r):
            if l > r:
                return None
            mid = inorder.index(preorder[i])
            root = TreeNode(preorder[i])
            root.left = dfs(i + 1, l, mid - 1)
            root.right = dfs(i + 1 + (mid - l), mid + 1, r)
            return root
        return dfs(0, 0, len(preorder) - 1)
