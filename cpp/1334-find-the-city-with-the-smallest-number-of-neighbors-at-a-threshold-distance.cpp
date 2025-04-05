#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto findTheCity(
            const unsigned n,
            const std::vector<std::vector<int>> &edges,
            const int distance_threshold
        ) -> int {
            auto distance_mat =
                std::vector<std::vector<int>>(n, std::vector<int>(n, 10'001));

            for (auto i = 0U; i < n; ++i) {
                distance_mat[i][i] = 0;
            }

            for (const auto &edge : edges) {
                const auto start = static_cast<unsigned>(edge[0]);
                const auto end = static_cast<unsigned>(edge[1]);
                const auto weight = edge[2];
                distance_mat[start][end] = weight;
                distance_mat[end][start] = weight;
            }

            // floyd
            for (auto k = 0U; k < n; ++k) {
                for (auto i = 0U; i < n; ++i) {
                    for (auto j = 0U; j < n; ++j) {
                        distance_mat[i][j] = std::min(
                            distance_mat[i][j],
                            distance_mat[i][k] + distance_mat[k][j]
                        );
                    }
                }
            }

            auto ans = 0U;
            auto fewest_reachable_count = n;

            for (auto i = 0U; i < n; ++i) {
                auto reachable_count = 0U;

                for (auto j = 0U; j < n; ++j) {
                    // i != j unnecessary since only want city with smallest
                    // count
                    if (distance_mat[i][j] <= distance_threshold) {
                        ++reachable_count;
                    }
                }

                if (reachable_count <= fewest_reachable_count) {
                    fewest_reachable_count = reachable_count;
                    ans = i;
                }
            }

            return static_cast<int>(ans);
        }
};
