#include <string_view>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto
        getLucky(const std::string_view s, const uint k) -> int {
            auto ans = 0;

            for (const auto c : s) {
                const auto t = c - 'a' + 1;
                ans += t / 10 + t % 10;
            }

            for (auto i = 1U; i < k; ++i) {
                auto t = 0;

                while (ans > 0) {
                    t += ans % 10;
                    ans /= 10;
                }

                ans = t;
            }

            return ans;
        }
};
