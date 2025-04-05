#include <algorithm>
#include <string>

class Solution {
    public:
        [[nodiscard]] constexpr auto judgeCircle(const std::string &moves
        ) const noexcept -> bool {
            // simulation
            // O(n)
            // O(1)
            // return std::ranges::count(moves, 'L') ==
            //            std::ranges::count(moves, 'R') &&
            //        std::ranges::count(moves, 'U') ==
            //        std::ranges::count(moves, 'D');

            auto x = 0U;
            auto y = 0U;

            for (const auto move : moves) {
                if (move == 'L') {
                    --x;
                } else if (move == 'R') {
                    ++x;
                } else if (move == 'U') {
                    --y;
                } else if (move == 'D') {
                    ++y;
                }
            }

            return x == 0 && y == 0;
        }
};
