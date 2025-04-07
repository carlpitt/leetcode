#include <cmath>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto maxAbsoluteSum(const std::vector<int> &nums
        ) const noexcept -> int {
            auto curr_max = nums[0];
            auto curr_min = nums[0];
            auto max_sum = nums[0];
            auto min_sum = nums[0];

            for (auto i = 1U; i < nums.size(); ++i) {
                const auto num = nums[i];
                curr_max = std::max(num, curr_max + num);
                curr_min = std::min(num, curr_min + num);
                max_sum = std::max(max_sum, curr_max);
                min_sum = std::min(min_sum, curr_min);
            }

            return std::max(std::abs(max_sum), std::abs(min_sum));
        }
};
