# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        
        pre_sum = {0: 1}
        ans = 0
        def dfs(node, curr_sum):
            nonlocal ans
            nonlocal pre_sum
            if not node:
                return 
            curr_sum += node.val
            ans += pre_sum.get(curr_sum - targetSum, 0)
            pre_sum[curr_sum] = pre_sum.get(curr_sum, 0) + 1
            dfs(node.left, curr_sum)
            dfs(node.right, curr_sum)

            pre_sum[curr_sum] -= 1
            if pre_sum[curr_sum] == 0:
                del pre_sum[curr_sum]

        dfs(root, 0)
        return ans