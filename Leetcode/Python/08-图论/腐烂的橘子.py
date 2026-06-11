from collections import deque
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        queue = deque()
        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    count += 1
        
        if count == 0:
            return 0
        min = 0
        dir = [(0, -1), (0, 1), (-1, 0), (1, 0)]

        while queue:
            size = len(queue)
            rotted_this_round = False
            for _ in range(size):
                x, y = queue.popleft()
                for dx, dy in dir:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 1:
                        queue.append((nx, ny))
                        grid[nx][ny] = 2
                        count -= 1
                        rotted_this_round = True
            
            if rotted_this_round:
                min += 1
        return min if count == 0 else -1


