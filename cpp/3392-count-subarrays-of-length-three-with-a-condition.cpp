#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto countSubarrays(const std::vector<int> &nums
        ) const noexcept -> uint {
            auto ans = 0U;

            for (auto i = 0U; i < nums.size() - 2; ++i) {
                if (2 * (nums[i] + nums[i + 2]) == nums[i + 1]) {
                    ++ans;
                }
            }

            return ans;
        }
};
