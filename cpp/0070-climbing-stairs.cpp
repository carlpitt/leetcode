#include <utility>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto climbStairs(const uint n) const noexcept
            -> uint {
            auto prev = 1U;
            auto curr = 1U;

            for (auto i = 1U; i < n; ++i) {
                prev = std::exchange(curr, prev + curr);
            }

            return curr;
        }
};
