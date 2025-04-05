#include <cstdint>

using i64 = std::int64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto isPalindrome(const int x) -> bool {
            auto t = x;
            auto r = i64{0};

            while (t > 0) {
                r = 10 * r + t % 10;
                t /= 10;
            }

            return x == r;

            // if (x < 0 || (x > 0 && x % 10 == 0)) {
            //     return false;
            // }

            // auto r = 0;

            // while (x > r) {
            //     r = 10 * r + x % 10;
            //     x /= 10;
            // }

            // return x == r / 10 || x == r;
        }
};
