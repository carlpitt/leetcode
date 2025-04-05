#include <algorithm>
#include <cstdint>
#include <vector>

using uint = unsigned;
using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto countFairPairs(
            std::vector<int> &nums,
            const int lower,
            const int upper
        ) const noexcept -> u64 {
            // // 1. binary search
            // // O(n * log(n))
            // // O(log(n)) for std::ranges::sort()
            // std::ranges::sort(nums);

            // const auto n = nums.size();
            // auto ans = u64{0};

            // for (auto i = 0U; i < n; ++i) {
            //     const auto num = nums[i];
            //     const auto low = lower_bound(nums, i + 1, n - 1, lower -
            //     num); const auto high = lower_bound(nums, i + 1, n - 1, upper
            //     - num + 1); ans += high - low;
            // }

            // return ans;

            // 2. 2 pointers
            // O(n * log(n))
            // O(log(n)) for std::ranges::sort()
            std::ranges::sort(nums);

            return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
        }

    private:
        [[nodiscard]] constexpr auto lower_bound(
            const std::vector<int> &nums,
            uint low,
            uint high,
            const int element
        ) const noexcept -> uint {
            while (low <= high) {
                const auto mid = low + (high - low) / 2;

                if (nums[mid] >= element) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return low;
        }

        [[nodiscard]] constexpr auto lower_bound(
            const std::vector<int> &nums,
            const int value
        ) const noexcept -> u64 {
            auto i = 0U;
            auto j = nums.size() - 1;
            auto ans = u64{0};

            while (i < j) {
                if (nums[i] + nums[j] < value) {
                    ans += j - i;
                    ++i;
                } else {
                    --j;
                }
            }

            return ans;
        }
};
