from collections import deque
from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        vt = [[0] * m for _ in range(n)] 
        dx = [0, 0, -1, 1]
        dy = [-1, 1, 0, 0]
        def bfs(x, y):
            q = deque()
            q.append([x, y])
            while q:
                x, y = q.popleft()
                
                for i in range(4):
                    nx = x + dx[i]
                    ny = y + dy[i]
                    if nx < 0 or nx > n - 1 or ny < 0 or ny > m - 1 or vt[nx][ny]:
                        continue
                    if grid[nx][ny] == '1':
                        vt[nx][ny] = 1
                        q.append([nx, ny])
        ans = 0
        for i in range(0, n):
            for j in range(0, m):
                if vt[i][j] == 1:
                    continue
                if grid[i][j] == '1':
                    ans += 1
                    vt[i][j] = 1
                    bfs(i,j)
        return ans

