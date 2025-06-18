#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
    public:
        static constexpr auto maxAdjacentDistance =
            [] [[nodiscard]] (const std::vector<int> &nums) noexcept -> int {
            const auto n = nums.size();
            auto ans = std::abs(nums[n - 1] - nums[0]);

            for (auto i = 0U; i < n - 1; ++i) {
                ans = std::max(ans, std::abs(nums[i + 1] - nums[i]));
            }

            return ans;
        };
};
