#include <algorithm>
#include <array>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto countLargestGroup(const uint n
        ) const noexcept -> uint {
            constexpr auto sum_digits = [](uint x) noexcept {
                auto ans = 0U;

                while (x > 0) {
                    ans += x % 10;
                    x /= 10;
                }

                return ans;
            };

            // auto freq = std::unordered_map<uint, uint>{};
            // auto freq = std::vector(sum_digits(n) + 1, 0U);
            auto freq = std::array<uint, 4 * 9 + 1>{};
            auto max = 0U;

            for (auto i = 1U; i <= n; ++i) {
                const auto sum = sum_digits(i);
                ++freq[sum];
                max = std::max(max, freq[sum]);
            }

            return static_cast<uint>(std::ranges::count(freq, max));
        }
};
