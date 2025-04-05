#include <array>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto numIdenticalPairs(
            const std::vector<int> &nums
        ) const noexcept -> uint {
            // O(n)
            // O(n)
            auto map = std::array<uint, 100>{};
            auto ans = 0U;

            for (const auto num : nums) {
                auto &freq = map[static_cast<uint>(num)];
                ans += freq;
                ++freq;
            }

            return ans;
        }
};
