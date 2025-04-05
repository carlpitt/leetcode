#include <array>
#include <queue>
#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto regionsBySlashes(
            const std::vector<std::string> &grid
        ) -> uint {
            const auto n = grid.size();
            auto expanded_grid = std::vector<std::vector<bool>>{3 * n};
            for (auto &v : expanded_grid) {
                v.resize(3 * n);
            }

            for (auto i = 0U; i < n; ++i) {
                for (auto j = 0U; j < n; ++j) {
                    const auto base_row = 3 * i;
                    const auto base_col = 3 * j;

                    if (grid[i][j] == '\\') {
                        expanded_grid[base_row][base_col] = true;
                        expanded_grid[base_row + 1][base_col + 1] = true;
                        expanded_grid[base_row + 2][base_col + 2] = true;
                    } else if (grid[i][j] == '/') {
                        expanded_grid[base_row][base_col + 2] = true;
                        expanded_grid[base_row + 1][base_col + 1] = true;
                        expanded_grid[base_row + 2][base_col] = true;
                    }
                }
            }

            auto ans = 0U;

            for (auto i = 0U; i < 3 * n; ++i) {
                for (auto j = 0U; j < 3 * n; ++j) {
                    if (!expanded_grid[i][j]) {
                        flood_fill(expanded_grid, i, j);

                        ++ans;
                    }
                }
            }

            return ans;
        }

    private:
        auto flood_fill(
            std::vector<std::vector<bool>> &expanded_grid,
            const uint row,
            const uint col
        ) -> void {
            constexpr auto directions = std::array{
                std::array{1U, 2U},
                std::array{1U, 0U},
                std::array{2U, 1U},
                std::array{0U, 1U}
            };
            auto q = std::queue<std::array<uint, 2>>{{{row, col}}};
            expanded_grid[row][col] = true;

            while (!q.empty()) {
                const auto &[curr_row, curr_col] = q.front();
                for (const auto &direction : directions) {
                    if (curr_row + direction[0] == 0) {
                        break;
                    }

                    const auto new_row = curr_row + direction[0] - 1;

                    if (curr_col + direction[1] == 0) {
                        break;
                    }

                    const auto new_col = curr_col + direction[1] - 1;

                    if (is_valid_cell(expanded_grid, new_row, new_col)) {
                        expanded_grid[new_row][new_col] = true;

                        q.push({new_row, new_col});
                    }
                }

                q.pop();
            }
        }

        [[nodiscard]] constexpr auto is_valid_cell(
            const std::vector<std::vector<bool>> &expanded_grid,
            const uint row,
            const uint col
        ) -> bool {
            const auto n = expanded_grid.size();

            return row < n && col < n && !expanded_grid[row][col];
        }
};
