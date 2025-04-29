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
            auto max_e_i = std::vector<uint>{};

            for (auto i = 0U; i < n; ++i) {
                if (nums[i] == max_e) {
                    max_e_i.push_back(i);
                }

                const auto freq = max_e_i.size();

                if (freq >= k) {
                    ans += max_e_i[freq - k] + 1;
                }
            }

            return ans;
        }
};
