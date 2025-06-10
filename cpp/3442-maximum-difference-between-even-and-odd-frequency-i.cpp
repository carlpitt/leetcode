#include <array>
#include <limits>
#include <string>

using uint = unsigned;

class Solution {
    public:
        static constexpr auto maxDifference =
            [] [[nodiscard]] (const std::string &s) noexcept -> uint {
            auto freq = std::array<uint, 'z' - 'a' + 1>{};

            for (const auto c : s) {
                ++freq[static_cast<uint>(c - 'a')];
            }

            auto max_odd = 1U;
            auto min_even = std::numeric_limits<uint>::max();

            for (const auto f : freq) {
                if (f % 2 == 1) {
                    max_odd = std::max(max_odd, f);
                } else if (f > 0) {
                    min_even = std::min(min_even, f);
                }
            }

            return max_odd - min_even;
        };
};
