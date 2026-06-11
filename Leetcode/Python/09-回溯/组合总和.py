from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        path = []
        n = len(candidates)
        def dfs(index: int, sum: int):
            if sum == target:
                ans.append(path[:])
                return 
            elif sum > target:
                return 
            for i in range(index, n):
                path.append(candidates[i])
                dfs(i, sum + candidates[i])
                path.pop()

        dfs(0, 0)
        return ans
