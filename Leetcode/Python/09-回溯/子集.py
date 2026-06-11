from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        path = []
        def dfs(startIndex: int):
            ans.append(path[:])
            for i in range(startIndex, n):
                path.append(nums[i])
                dfs(i + 1)
                path.pop()
                
        dfs(0)
        return ans