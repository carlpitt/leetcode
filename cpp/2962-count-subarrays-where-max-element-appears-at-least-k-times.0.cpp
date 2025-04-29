#include <algorithm>
#include <cstdint>
#include <vector>

using uint = unsigned;
using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto countSubarrays(
            const std::vector<int> &nums,
            const uint k
        ) const noexcept -> u64 {
            const auto n = nums.size();
            const auto max_e = std::ranges::max(nums);
            auto ans = u64{0};
            auto i = 0U;
            auto num_max_e_in_window = 0U;

            for (auto j = 0U; j < n; ++j) {
                if (nums[j] == max_e) {
                    ++num_max_e_in_window;
                }

                while (num_max_e_in_window == k) {
                    if (nums[i] == max_e) {
                        --num_max_e_in_window;
                    }

                    ++i;
                }

                ans += i;
            }

            return ans;
        }
};
