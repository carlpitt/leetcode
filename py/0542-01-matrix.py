# from collections import deque


class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        m = len(mat)
        n = len(mat[0])

        # q = deque[tuple[int, int]]()

        # for r in range(m):
        #     for c in range(n):
        #         if mat[r][c] == 0:
        #             q.append((r, c))
        #         else:
        #             mat[r][c] = -1

        # d = (0, 1, 0, -1, 0)

        # while len(q) > 0:
        #     (r, c) = q.popleft()

        #     for i in range(len(d) - 1):
        #         nr = r + d[i]
        #         nc = c + d[i + 1]

        #         if nr < 0 or nr == m or nc < 0 or nc == n or mat[nr][nc] != -1:
        #             continue

        #         mat[nr][nc] = mat[r][c] + 1

        #         q.append((nr, nc))

        for r in range(m):
            for c in range(n):
                if mat[r][c] > 0:
                    top = mat[r - 1][c] if r > 0 else 10_001
                    left = mat[r][c - 1] if c > 0 else 10_001
                    mat[r][c] = min(top, left) + 1

        for r in range(m - 1, -1, -1):
            for c in range(n - 1, -1, -1):
                if mat[r][c] > 0:
                    bottom = mat[r + 1][c] if r < m - 1 else 10_001
                    right = mat[r][c + 1] if c < n - 1 else 10_001
                    mat[r][c] = min(mat[r][c], bottom + 1, right + 1)

        return mat
