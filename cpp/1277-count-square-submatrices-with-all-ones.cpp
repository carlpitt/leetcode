#include <algorithm>
#include <vector>

using usize = std::size_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto countSquares(
            std::vector<std::vector<int>> &matrix
        ) const noexcept -> int {
            // // 1. top-down dp
            // // O(row * col)
            // // O(row * col)
            // const auto rows = matrix.size();
            // const auto cols = matrix[0].size();
            // auto ans = 0;
            // auto dp = std::vector(rows, std::vector(cols, -1));

            // for (auto i = 0UZ; i < rows; ++i) {
            //     for (auto j = 0UZ; j < cols; ++j) {
            //         ans += solve(i, j, matrix, dp);
            //     }
            // }

            // return ans;

            // 2. top-down dp
            // O(row * col)
            // O(1)
            const auto rows = matrix.size();
            const auto cols = matrix[0].size();
            auto ans = 0;

            for (auto i = 0UZ; i < rows; ++i) {
                for (auto j = 0UZ; j < cols; ++j) {
                    if (matrix[i][j] == 1) {
                        if (i > 0 && j > 0) {
                            matrix[i][j] += std::min(
                                {matrix[i - 1][j - 1],
                                 matrix[i - 1][j],
                                 matrix[i][j - 1]}
                            );
                        }

                        ans += matrix[i][j];
                    }
                }
            }

            return ans;
        }

    private:
        [[nodiscard]] constexpr auto solve(
            const usize i,
            const usize j,
            const std::vector<std::vector<int>> &matrix,
            std::vector<std::vector<int>> &dp
        ) const noexcept -> int {
            if (i >= matrix.size() || j >= matrix[0].size() ||
                matrix[i][j] == 0) {
                return 0;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            const auto right = solve(i, j + 1, matrix, dp);
            const auto diagonal = solve(i + 1, j + 1, matrix, dp);
            const auto below = solve(i + 1, j, matrix, dp);

            dp[i][j] = std::min({right, diagonal, below}) + 1;

            return dp[i][j];
        }
};
