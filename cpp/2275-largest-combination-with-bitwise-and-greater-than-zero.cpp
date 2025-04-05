#include <algorithm>
#include <array>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto largestCombination(
            const std::vector<int> &candidates
        ) const noexcept -> uint {
            // // 1. bit count array
            // // O(n * b + b) == O(n)
            // // O(b) == O(1)
            // auto bit_count = std::array<uint, 24>{};

            // for (auto i = 0U; i < 24; ++i) {
            //     for (const auto candidate : candidates) {
            //         if ((candidate & (1 << i)) != 0) {
            //             ++bit_count[i];
            //         }
            //     }
            // }

            // return std::ranges::max(bit_count);

            // 2. direct max bit count
            // O(n * b) == O(n)
            // O(1)
            auto ans = 0U;

            for (auto i = 0U; i < 24; ++i) {
                const auto count = static_cast<uint>(std::ranges::count_if(
                    candidates,
                    [i](const int candidate) {
                        return (candidate & (1 << i)) != 0;
                    }
                ));
                ans = std::max(ans, count);
            }

            return ans;
        }
};
