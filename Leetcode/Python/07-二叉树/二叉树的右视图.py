# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        st = []
        st.append(root)
        ans = []
        while len(st):
            new_st = []
            ans.append(st[-1].val)
            for node in st:
                if node.left:
                    new_st.append(node.left)
                if node.right:
                    new_st.append(node.right)

            st = new_st
        return ans