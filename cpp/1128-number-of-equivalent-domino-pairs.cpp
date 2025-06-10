#include <array>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        static constexpr auto numEquivDominoPairs =
            [] [[nodiscard]] (
                const std::vector<std::vector<int>> &dominoes
            ) noexcept -> uint {
            auto freq = std::array<uint, 100>{};
            auto ans = 0U;

            for (const auto &domino : dominoes) {
                const auto x = static_cast<uint>(
                    10 * std::min(domino[0], domino[1]) +
                    std::max(domino[0], domino[1])
                );
                ans += freq[x];
                ++freq[x];
            }

            return ans;
        };
};
