#include <algorithm>
#include <array>
#include <utility>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto primeSubOperation(
            const std::vector<int> &nums
        ) const noexcept -> bool {
            // // 1. brute force
            // // O(n * m * sqrt(m))
            // // O(1)
            // const auto n = nums.size();

            // for (auto i = 0U; i < n; ++i) {
            //     const auto [bound, fail] = [i, &nums]() {
            //         if (i == 0) {
            //             return std::pair{nums[0], false};
            //         }

            //         return std::pair{nums[i] - nums[i - 1], nums[i] <= nums[i
            //         - 1]};
            //     }();

            //     if (fail) {
            //         return false;
            //     }

            //     const auto largest_prime = [bound, this]() {
            //         for (auto j = bound - 1; j >= 2; --j) {
            //             if (is_prime(j)) {
            //                 return j;
            //             }
            //         }

            //         return 0;
            //     }();
            //     nums[i] -= largest_prime;
            // }

            // return true;

            // // 2. storing the primes
            // // O(n + m * sqrt(m))
            // // O(m)
            // const auto n = nums.size();
            // const auto max_element = std::ranges::max(nums);
            // auto prev_prime = std::vector(max_element + 1, 0U);

            // for (auto i = 2U; i <= max_element; ++i) {
            //     if (is_prime(i)) {
            //         prev_prime[i] = i;
            //     } else {
            //         prev_prime[i] = prev_prime[i - 1];
            //     }
            // }

            // for (auto i = 0U; i < n; ++i) {
            //     const auto [bound, fail] = [i, &nums]() {
            //         if (i == 0) {
            //             return std::pair{nums[0], false};
            //         }

            //         return std::pair{nums[i] - nums[i - 1], nums[i] <= nums[i
            //         - 1]};
            //     }();

            //     if (fail) {
            //         return false;
            //     }

            //     const auto largest_prime = prev_prime[bound - 1];
            //     nums[i] -= largest_prime;
            // }

            // return true;

            // 3. sieve of eratosthenes and 2 pointers
            // O(n + m * log(log(m)))
            // O(m)
            const auto max_element = static_cast<uint>(std::ranges::max(nums));
            auto sieve = std::vector(max_element + 1, true);
            sieve[1] = false;

            for (auto i = 2U; i * i <= max_element; ++i) {
                if (sieve[i]) {
                    for (auto j = i * i; j <= max_element; j += i) {
                        sieve[j] = false;
                    }
                }
            }

            auto i = 0U;
            auto curr = 1;

            while (i < nums.size()) {
                const auto diff = nums[i] - curr;

                if (diff < 0) {
                    return false;
                }

                if (diff == 0 || sieve[static_cast<uint>(diff)]) {
                    ++i;
                }

                ++curr;
            }

            return true;
        }

    private:
        [[nodiscard]] constexpr auto is_prime(const uint x) const noexcept
            -> bool {
            for (auto i = 2U; i * i <= x; ++i) {
                if (x % i == 0) {
                    return false;
                }
            }

            return true;
        }
};
