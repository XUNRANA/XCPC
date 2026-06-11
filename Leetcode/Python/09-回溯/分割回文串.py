from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        ans = []
        path = []
        def check(sub: str) -> bool:
            return sub == sub[::-1]
        def backtrack(index: int):
            if index == n:
                ans.append(path[:])
                return 
            for i in range(index, n):
                sub = s[index: i + 1]
                if check(sub):
                    path.append(sub)
                    backtrack(i + 1)
                    path.pop()
        backtrack(0)
        return ans