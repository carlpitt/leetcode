#include <array>
#include <cstdint>

using uint = unsigned;
using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto minEnd(uint n, const uint x) const noexcept
            -> u64 {
            // // 1. consecutive or-ing
            // // O(n)
            // // O(1)
            // auto ans = u64{x};

            // for (auto i = 0U; i < n - 1; ++i) {
            //     ans = (ans + 1) | x;
            // }

            // return ans;

            // // 2. bit manipulation and binary construction
            // // O(64) == O(1)
            // // O(64) == O(1)
            // const auto long_x = u64{x};
            // const auto long_n = u64{n - 1};
            // auto binary_x = std::array<uint, 64>{};
            // auto binary_n = std::array<uint, 64>{};

            // for (auto i = 0U; i < 64; ++i) {
            //     binary_x[i] = (long_x >> i) & 1;
            //     binary_n[i] = (long_n >> i) & 1;
            // }

            // auto pos_x = 0U;
            // auto pos_n = 0U;

            // while (pos_x < 63) {
            //     while (binary_x[pos_x] > 0 && pos_x < 63) {
            //         ++pos_x;
            //     }

            //     binary_x[pos_x] = binary_n[pos_n];
            //     ++pos_x;
            //     ++pos_n;
            // }

            // auto ans = u64{0};

            // for (auto i = 0U; i < 64; ++i) {
            //     if (binary_x[i] == 1) {
            //         ans += u64{1} << i;
            //     }
            // }

            // return ans;

            // 3. bitmasking with logical operations
            // O(log_2(n)) == O(b) == O(1)
            // O(1)
            auto ans = u64{x};
            auto mask = u64{1};
            --n;

            while (n > 0) {
                if ((mask & x) == 0) {
                    ans |= (n & 1) * mask;
                    n >>= 1;
                }

                mask <<= 1;
            }

            return ans;
        }
};
