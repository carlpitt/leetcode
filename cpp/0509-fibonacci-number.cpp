#include <utility>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto fib(const uint n) noexcept -> uint {
            if (n == 0) {
                return 0;
            }

            auto a = 0U;
            auto b = 1U;

            for (auto i = 1U; i < n; ++i) {
                a = std::exchange(b, a + b);
            }

            return b;
        }
};
