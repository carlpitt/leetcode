#include <array>
#include <limits>
#include <utility>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto closestPrimes(
            const uint left,
            const uint right
        ) const noexcept -> std::vector<int> {
            // sieve of eratosthenes
            auto sieve = std::array<bool, 1'000'001>{};

            sieve.fill(true);

            sieve[1] = false;

            for (auto i = 2U; i * i <= right; ++i) {
                if (!sieve[i]) {
                    continue;
                }

                for (auto j = i * i; j <= right; j += i) {
                    sieve[j] = false;
                }
            }

            constexpr auto max = std::numeric_limits<uint>::max();
            auto num1 = max;
            auto num2 = max;
            auto prev = max;

            for (auto i = left; i <= right; ++i) {
                if (!sieve[i]) {
                    continue;
                }

                if (num1 == max) {
                    num1 = i;

                    continue;
                }

                if (num2 == max) {
                    num2 = i;

                    continue;
                }

                if (i - num2 < num2 - num1) {
                    num1 = std::exchange(num2, i);

                    continue;
                }

                if (prev != max && i - prev < num2 - num1) {
                    num1 = prev;
                    num2 = i;

                    continue;
                }

                prev = i;
            }

            if (num2 == max) {
                return std::vector{-1, -1};
            }

            return std::vector{static_cast<int>(num1), static_cast<int>(num2)};
        }
};
