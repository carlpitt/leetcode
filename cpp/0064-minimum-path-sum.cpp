#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto minPathSum(
            std::vector<std::vector<int>> &grid
        ) -> int {
            const auto m = grid.size();
            const auto n = grid[0].size();

            for (auto i = 1U; i < n; ++i) {
                grid[0][i] += grid[0][i - 1];
            }

            for (auto i = 1U; i < m; ++i) {
                grid[i][0] += grid[i - 1][0];

                for (auto j = 1U; j < n; ++j) {
                    grid[i][j] += std::min(grid[i][j - 1], grid[i - 1][j]);
                }
            }

            return grid[m - 1][n - 1];
        }
};
