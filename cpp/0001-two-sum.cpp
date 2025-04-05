#include <unordered_map>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto twoSum(
            const std::vector<int> &nums,
            const int target
        ) const noexcept -> std::vector<int> {
            auto d = std::unordered_map<int, int>{};

            for (auto i = 0U; i < nums.size(); ++i) {
                const auto n = nums[i];
                const auto diff = target - n;

                if (d.contains(diff)) {
                    return std::vector{d[diff], static_cast<int>(i)};
                }

                d[n] = static_cast<int>(i);
            }

            return std::vector<int>{};
        }
};
