// https://leetcode.com/problems/number-of-enclaves

#include <iostream>
#include <vector>

// TODO
class Solution {
    public:
        bool issafe(std::vector<std::vector<int>> grid, int i, int j) {
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
                grid[i][j] != 1) {
                return false;
            }
            return true;
        }

        void dfs(std::vector<std::vector<int>> &grid, int i, int j) {
            grid[i][j] = 0;
            int x_arr[4] = {0, 0, 1, -1};
            int y_arr[4] = {1, -1, 0, 0};
            for (int k = 0; k < 4; k++) {
                if (issafe(grid, i + x_arr[k], j + y_arr[k])) {
                    dfs(grid, i + x_arr[k], j + y_arr[k]);
                }
            }
        }

        int numEnclaves(std::vector<std::vector<int>> &grid) {
            for (int i = 0; i < grid.size(); i++) {
                if (grid[i][0] == 1) {
                    dfs(grid, i, 0);
                }
                if (grid[i][grid[0].size() - 1] == 1) {
                    dfs(grid, i, grid[0].size() - 1);
                }
            }
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[0][j] == 1) {
                    dfs(grid, 0, j);
                }
                if (grid[grid.size() - 1][j] == 1) {
                    dfs(grid, grid.size() - 1, j);
                }
            }
            int count = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 1) {
                        count++;
                    }
                }
            }
            return count;
        }
};

int main() {}
