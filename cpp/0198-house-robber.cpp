#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto rob(const std::vector<int> &nums) -> int {
            auto prev0 = 0;
            auto prev1 = 0;

            for (const auto num : nums) {
                const auto temp = prev0;
                prev0 = std::max(prev0, prev1 + num);
                prev1 = temp;
            }

            return prev0;
        }
};
