#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto maximumCount(const std::vector<int> &nums
        ) const noexcept -> std::size_t {
            const auto n = nums.size();
            auto i = 0UZ;

            while (i < n && nums[i] < 0) {
                ++i;
            }

            const auto neg = i;

            while (i < n && nums[i] == 0) {
                ++i;
            }

            return std::max(neg, n - i);
        }
};
