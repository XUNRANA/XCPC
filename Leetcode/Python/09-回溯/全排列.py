from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        path = []
        ans = []
        visited = [False] * n
        def dfs():
            if len(path) == n:
                ans.append(path[:])
                return
            for i in range(n):
                if visited[i]:
                    continue
                visited[i] = True
                path.append(nums[i])
                dfs()
                path.pop()
                visited[i] = False
        dfs()
        return ans