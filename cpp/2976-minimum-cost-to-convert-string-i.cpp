#include <cstdint>
#include <limits>
#include <string>
#include <vector>

using i64 = std::int64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumCost(
            const std::string &source,
            const std::string &target,
            const std::vector<char> &original,
            const std::vector<char> &changed,
            const std::vector<int> &cost
        ) -> i64 {
            constexpr auto max = std::numeric_limits<int>::max();
            auto min_cost =
                std::vector<std::vector<i64>>(26, std::vector<i64>(26, max));

            for (auto i = 0U; i < original.size(); ++i) {
                const auto start = static_cast<unsigned>(original[i] - 'a');
                const auto end = static_cast<unsigned>(changed[i] - 'a');
                min_cost[start][end] =
                    std::min(min_cost[start][end], static_cast<i64>(cost[i]));
            }

            for (auto k = 0U; k < 26; ++k) {
                for (auto i = 0U; i < 26; ++i) {
                    for (auto j = 0U; j < 26; ++j) {
                        min_cost[i][j] = std::min(
                            min_cost[i][j],
                            min_cost[i][k] + min_cost[k][j]
                        );
                    }
                }
            }

            auto ans = i64{0};

            for (auto i = 0U; i < source.size(); ++i) {
                if (source[i] == target[i]) {
                    continue;
                }

                const auto source_c = static_cast<unsigned>(source[i] - 'a');
                const auto target_c = static_cast<unsigned>(target[i] - 'a');

                if (min_cost[source_c][target_c] == max) {
                    return -1;
                }

                ans += min_cost[source_c][target_c];
            }

            return ans;
        }
};
