#include <algorithm>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto maximumCount(
            const std::vector<int> &nums
        ) const noexcept -> std::size_t {
            const auto neg =
                std::distance(nums.begin(), std::ranges::lower_bound(nums, 0));
            const auto pos =
                std::distance(std::ranges::upper_bound(nums, 0), nums.end());

            return std::max(neg, pos);
        }
};
