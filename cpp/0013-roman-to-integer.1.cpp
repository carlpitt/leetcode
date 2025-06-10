#include <array>
#include <string>

using uint = unsigned;

class Solution {
    public:
        static constexpr auto romanToInt =
            [] [[nodiscard]] (const std::string s) noexcept -> uint {
            constexpr auto a = [] {
                auto ans = std::array<uint, 'X' - 'C' + 1>{};
                ans['I' - 'C'] = 1;
                ans['V' - 'C'] = 5;
                ans['X' - 'C'] = 10;
                ans['L' - 'C'] = 50;
                ans['C' - 'C'] = 100;
                ans['D' - 'C'] = 500;
                ans['M' - 'C'] = 1000;

                return ans;
            }();
            auto ans = 0U;
            auto prev = 1001U;

            for (const auto c : s) {
                const auto curr = a[static_cast<uint>(c - 'C')];

                if (curr > prev) {
                    ans -= 2 * prev;
                }

                ans += curr;
                prev = curr;
            }

            return ans;
        };
};
