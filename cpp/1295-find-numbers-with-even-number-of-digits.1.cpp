#include <cmath>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findNumbers(
            const std::vector<int> &nums
        ) const noexcept -> uint {
            auto ans = 0U;

            for (const auto num : nums) {
                if (static_cast<uint>(std::log10(num) + 1) % 2 == 0) {
                    ++ans;
                }
            }

            return ans;
        }
};
