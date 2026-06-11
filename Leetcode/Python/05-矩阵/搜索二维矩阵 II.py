from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
          return False

        row, col = 0, len(matrix[0]) - 1  # 右上角

        while row < len(matrix) and col >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                col -= 1    # 当前值太大，往左走
            else:
                row += 1    # 当前值太小，往下走

        return False
