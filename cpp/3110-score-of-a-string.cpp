#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto scoreOfString(const std::string &s)
            -> uint {
            auto ans = 0U;

            for (auto i = 0U; i < s.size() - 1; ++i) {
                ans += static_cast<uint>(std::abs(s[i] - s[i + 1]));
            }

            return ans;
        }
};
