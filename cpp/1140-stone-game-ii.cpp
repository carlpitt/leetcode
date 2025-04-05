#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto stoneGameII(const std::vector<int> &piles)
            -> int {
            const auto n = piles.size();

            auto suffix_sum = std::vector<int>{};
            suffix_sum.resize(n + 1);
            for (auto i = n - 1; i > 0; --i) {
                suffix_sum[i] = suffix_sum[i + 1] + piles[i];
            }
            suffix_sum[0] = suffix_sum[1] + piles[0];

            auto dp = std::vector<std::vector<int>>{n + 1};
            for (auto &v : dp) {
                v.resize(n + 1);
            }

            for (auto i = 0uz; i <= n; ++i) {
                dp[i][n] = suffix_sum[i];
            }

            // m is max till now
            for (auto i = n - 1; i > 0; --i) {
                for (auto m = 1uz; m < n; ++m) {
                    for (auto x = 1uz; x <= std::min(2 * m, n - i); ++x) {
                        dp[i][m] = std::max(
                            dp[i][m],
                            suffix_sum[i] - dp[i + x][std::max(m, x)]
                        );
                    }
                }
            }

            for (auto x = 1uz; x <= std::min(n, 2uz); ++x) {
                dp[0][1] = std::max(dp[0][1], suffix_sum[0] - dp[x][x]);
            }

            return dp[0][1];
        }
};
