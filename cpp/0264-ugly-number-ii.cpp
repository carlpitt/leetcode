#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto nthUglyNumber(const uint n) -> uint {
            auto u = std::vector<uint>{};
            u.resize(n);
            u[0] = 1;

            auto i2 = 0U;
            auto i3 = 0U;
            auto i5 = 0U;

            for (auto i = 1U; i < n; ++i) {
                u[i] = std::min(std::min(2 * u[i2], 3 * u[i3]), 5 * u[i5]);

                if (u[i] == 2 * u[i2]) {
                    ++i2;
                }

                if (u[i] == 3 * u[i3]) {
                    ++i3;
                }

                if (u[i] == 5 * u[i5]) {
                    ++i5;
                }
            }

            return u[n - 1];
        }
};
