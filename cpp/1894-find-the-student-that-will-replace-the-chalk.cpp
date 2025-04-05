#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using uint = unsigned;
using i64 = std::int64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto chalkReplacer(
            const std::vector<int> &chalk,
            int k
        ) const noexcept -> uint {
            // auto sum = 0;

            // for (const auto i : chalk) {
            //     sum += i;

            //     if (sum > k) {
            //         break;
            //     }
            // }

            // k %= sum;

            // for (auto i = 0; i < chalk.size(); ++i) {
            //     if (chalk[i] > k) {
            //         return i;
            //     }

            //     k -= chalk[i];
            // }

            // return 0;

            const auto n = chalk.size();
            auto prefix_sum = std::vector<i64>(n);

            prefix_sum[0] = chalk[0];

            for (auto i = 1U; i < n; ++i) {
                prefix_sum[i] = prefix_sum[i - 1] + chalk[i];
            }

            k %= prefix_sum[n - 1];

            return static_cast<uint>(
                std::ranges::upper_bound(prefix_sum, k) - prefix_sum.begin()
            );

            // auto low = 0U;
            // auto high = n - 1;

            // while (low < high) {
            //     const auto mid = low + (high - low) / 2;

            //     if (prefix_sum[mid] <= k) {
            //         low = mid + 1;
            //     } else {
            //         high = mid;
            //     }
            // }

            // return high;
        }
};
