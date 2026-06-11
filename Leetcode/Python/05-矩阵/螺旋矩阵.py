from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)
        m = len(matrix[0])
        r1 = 0
        rn = n - 1
        c1 = 0
        cn = m - 1

        ans = []
        while r1 <= rn and c1 <= cn:
            for i in range(c1, cn + 1):
                ans.append(matrix[r1][i])
            r1 += 1

            for i in range(r1, rn + 1):
                ans.append(matrix[i][cn])
            cn -= 1

            if r1 <= rn:
                for i in range(cn, c1 - 1, -1):
                    ans.append(matrix[rn][i])
                rn -= 1

            if c1 <= cn:
                for i in range(rn, r1 - 1, -1):
                    ans.append(matrix[i][c1])
                c1 += 1

        return ans


