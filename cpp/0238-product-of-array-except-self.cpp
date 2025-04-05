#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto productExceptSelf(
            const std::vector<int> &nums
        ) const noexcept -> std::vector<int> {
            // O(n)
            // O(n) including output
            const auto n = nums.size();
            auto ans = std::vector(n, 1);
            auto prefix = 1;
            auto suffix = 1;

            for (auto i = 0U; i < n; ++i) {
                ans[i] *= prefix;
                prefix *= nums[i];
                ans[n - i - 1] *= suffix;
                suffix *= nums[n - i - 1];
            }

            return ans;
        }
};
