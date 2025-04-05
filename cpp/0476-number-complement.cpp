#include <limits>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findComplement(const uint num) -> uint {
            // auto curr = 1U;

            // while (curr - 1 < num) {
            //     curr <<= 1;
            // }

            // return (curr - 1) ^ num;

            auto mask = std::numeric_limits<uint>::max();

            while (mask & num) {
                mask <<= 1;
            }

            return ~num ^ mask;
        }
};
