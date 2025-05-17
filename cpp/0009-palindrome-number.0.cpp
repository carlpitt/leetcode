#include <cstdint>

using i64 = std::int64_t;

class Solution {
    public:
        static constexpr auto isPalindrome = [] [[nodiscard]] (const int x
                                             ) noexcept -> bool {
            auto t = x;
            auto r = i64{0};

            while (t > 0) {
                r = 10 * r + t % 10;
                t /= 10;
            }

            return x == r;
        };
};
