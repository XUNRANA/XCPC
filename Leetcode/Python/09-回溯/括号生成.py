from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        path = []

        def backtrack(left_count: int, right_count: int):
            if left_count == n and right_count == n:
                ans.append("".join(path))
                return 
            if left_count < n:
                path.append('(')
                backtrack(left_count + 1, right_count)
                path.pop()
            if right_count < left_count:
                path.append(')')
                backtrack(left_count, right_count + 1)
                path.pop()

        backtrack(0, 0)
        return ans
