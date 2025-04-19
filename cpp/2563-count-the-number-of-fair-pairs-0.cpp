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
		// binary search
            // // O(n * log(n))
            // // O(log(n)) for std::ranges::sort()
            std::ranges::sort(nums);

            const auto n = nums.size();
            auto ans = u64{0};

            for (auto i = 0U; i < n; ++i) {
                const auto num = nums[i];
                const auto low = std::lower_bound(
                    nums.begin() + i + 1,
                    nums.end(),
                    lower - num
                );
                const auto high = std::lower_bound(
                    nums.begin() + i + 1,
                    nums.end(),
                    upper - num + 1
                );
                ans += static_cast<u64>(high - low);
            }

            return ans;
        }
};
