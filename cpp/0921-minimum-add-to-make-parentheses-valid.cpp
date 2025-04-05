#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minAddToMakeValid(const std::string &s
        ) const noexcept -> uint {
            auto unmatched_open = 0U;
            auto unmatched_close = 0U;

            for (const auto c : s) {
                if (c == '(') {
                    ++unmatched_open;
                } else if (unmatched_open > 0) {
                    --unmatched_open;
                } else {
                    ++unmatched_close;
                }
            }

            return unmatched_open + unmatched_close;
        }
};
