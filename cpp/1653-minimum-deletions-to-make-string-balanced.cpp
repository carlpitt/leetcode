#include <string>

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumDeletions(const std::string &s)
            -> unsigned {
            auto ans = 0U;
            auto b_count = 0U;

            for (const auto c : s) {
                if (c == 'b') {
                    ++b_count;
                } else {
                    ans = std::min(ans + 1, b_count);
                }
            }

            return ans;
        }
};
