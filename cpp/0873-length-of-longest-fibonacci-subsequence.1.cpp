#include <algorithm>
#include <limits>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto lenLongestFibSubseq(
            const std::vector<int> &arr
        ) const noexcept -> std::size_t {
            const auto n = arr.size();
            auto ans = 0UZ;
            auto dp = std::vector(n, std::vector(n, 0UZ));
            auto val_to_i = std::unordered_map<int, std::size_t>{};

            for (auto i = 0UZ; i < n; ++i) {
                val_to_i[arr[i]] = i;

                for (auto j = 0UZ; j < i; ++j) {
                    constexpr auto max =
                        std::numeric_limits<std::size_t>::max();
                    const auto diff = arr[i] - arr[j];
                    const auto prev_i =
                        [](std::unordered_map<int, std::size_t> &map,
                           const int d) {
                            if (!map.contains(d)) {
                                return max;
                            }

                            return map[d];
                        }(val_to_i, diff);

                    if (diff < arr[j] && prev_i < max) {
                        dp[j][i] = dp[prev_i][j] + 1;
                    } else {
                        dp[j][i] = 2;
                    }

                    ans = std::max(ans, dp[j][i]);
                }
            }

            if (ans < 3) {
                return 0;
            }

            return ans;
        }
};
