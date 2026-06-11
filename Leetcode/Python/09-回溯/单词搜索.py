from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        m = len(board[0])
        visited = [[0] * m for _ in range(n)]
        l = len(word)
        dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        def dfs(x: int, y: int, step: int) -> bool:
           
            if board[x][y] != word[step]:
                return False
            if step == len(word) - 1:
                return True
            visited[x][y] = 1
            for dx, dy in dir:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < n and 0 <= ny < m and visited[nx][ny] == 0:
                    if dfs(nx, ny, step + 1):
                        return True
            visited[x][y] = 0
            return False
            
            

        for i in range(n):
            for j in range(m):
                if dfs(i, j, 0):
                    return True
        return False
