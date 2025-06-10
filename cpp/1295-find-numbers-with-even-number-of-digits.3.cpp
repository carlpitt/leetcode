#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findNumbers(
            const std::vector<int> &nums
        ) const noexcept -> uint {
            auto ans = 0U;

            for (const auto num : nums) {
                if ((num >= 10 && num <= 99) || (num >= 1000 && num <= 9999) ||
                    num == 100'000) {
                    ++ans;
                }
            }

            return ans;
        }
};
