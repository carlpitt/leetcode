#include <algorithm>
#include <array>
#include <cstdint>
#include <numeric>
#include <vector>

using uint = unsigned;
using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto rangeSum(
            const std::vector<int> &nums,
            const uint n,
            const uint left,
            const uint right
        ) -> uint {
            constexpr auto mod = 1'000'000'007;

            // auto new_a = std::vector<uint>{};
            // new_a.reserve(n * (n + 1) / 2);

            // for (auto i = 0U; i < n; ++i) {
            //     auto sum = 0U;

            //     for (auto j = 0U; j < n - i; ++j) {
            //         sum += static_cast<uint>(nums[i + j]);

            //         new_a.push_back(sum);
            //     }
            // }

            // std::ranges::sort(new_a);

            // auto ans = 0U;

            // for (auto i = left - 1; i < right; ++i) {
            //     ans = (ans + new_a[i]) % mod;
            // }

            // return ans;

            return static_cast<uint>(
                (sum_of_first_k(nums, n, right) -
                 sum_of_first_k(nums, n, left - 1)) %
                mod
            );
        }

    private:
        [[nodiscard]] constexpr auto
        sum_of_first_k(const std::vector<int> &nums, const uint n, const uint k)
            -> u64 {
            auto left = static_cast<uint>(*std::ranges::min_element(nums));
            auto right = std::accumulate(nums.begin(), nums.end(), 0U);

            while (left <= right) {
                const auto mid = left + (right - left) / 2;

                if (count_and_sum(nums, n, mid)[0] >= k) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            const auto [count, sum] = count_and_sum(nums, n, left);

            return sum - left * (count - k);
        }

        [[nodiscard]] constexpr auto count_and_sum(
            const std::vector<int> &nums,
            const uint n,
            const uint target
        ) -> std::array<u64, 2> {
            auto count = 0U;
            auto currentSum = u64{0};
            auto totalSum = u64{0};
            auto windowSum = u64{0};
            auto i = 0U;

            for (auto j = 0U; j < n; ++j) {
                const auto num = static_cast<uint>(nums[j]);
                currentSum += num;
                windowSum += num * (j - i + 1);

                while (currentSum > target) {
                    windowSum -= currentSum;
                    currentSum -= static_cast<uint>(nums[i]);
                    ++i;
                }

                count += j - i + 1;
                totalSum += windowSum;
            }

            return {count, totalSum};
        }
};
