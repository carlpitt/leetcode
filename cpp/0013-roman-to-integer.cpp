#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto romanToInt(const std::string &s
        ) const noexcept -> uint {
            auto ans = 0U;
            auto prev = 1001U;

            for (const auto c : s) {
                const auto curr = [c]() {
                    switch (c) {
                        case 'I':
                            return 1U;
                        case 'V':
                            return 5U;
                        case 'X':
                            return 10U;
                        case 'L':
                            return 50U;
                        case 'C':
                            return 100U;
                        case 'D':
                            return 500U;
                        default /* 'M' */:
                            return 1000U;
                    }
                }();

                if (curr > prev) {
                    ans -= 2 * prev;
                }

                ans += curr;
                prev = curr;
            }

            return ans;
        }
};
