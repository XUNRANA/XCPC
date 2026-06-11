from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        set_r = set()
        set_c = set()
        n = len(matrix)
        m = len(matrix[0])
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    set_r.add(i)
                    set_c.add(j)
        for i in set_r:
            for j in range(m):
                matrix[i][j] = 0
        
        for i in range(n):
            for j in set_c:
                matrix[i][j] = 0
        