class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0

        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 0: continue
                if i == 0 or grid[i - 1][j] == 0: ans += 1
                if i == m - 1 or grid[i + 1][j] == 0: ans += 1
                if j == 0 or grid[i][j - 1] == 0: ans += 1
                if j == n - 1 or grid[i][j + 1] == 0: ans += 1
        return ans
