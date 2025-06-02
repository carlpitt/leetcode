#include <vector>

class Solution {
    public:
        static constexpr auto twoSum = [] [[nodiscard]] (
                                           const std::vector<int> &nums,
                                           const int target
                                       ) noexcept -> std::vector<int> {
            const auto n = nums.size();

            for (auto i = 0U; i < n; ++i) {
                for (auto j = i + 1; j < n; ++j) {
                    if (nums[j] == target - nums[i]) {
                        return std::vector{
                            static_cast<int>(i),
                            static_cast<int>(j)
                        };
                    }
                }
            }

            return std::vector<int>{};
        };
};
