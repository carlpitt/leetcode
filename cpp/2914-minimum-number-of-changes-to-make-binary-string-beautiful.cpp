#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minChanges(
            const std::string &s
        ) const noexcept -> uint {
            // // 1. greedy
            // // O(n)
            // // O(1)
            // auto c = s[0];
            // auto consecutive_count = 0U;
            // auto ans = 0U;

            // for (auto i = 0U; i < s.size(); ++i) {
            //     if (s[i] == c) {
            //         ++consecutive_count;

            //         continue;
            //     }

            //     if (consecutive_count % 2 == 0) {
            //         consecutive_count = 1;
            //     } else {
            //         consecutive_count = 0;
            //         ++ans;
            //     }

            //     c = s[i];
            // }

            // return ans;

            // 2. optimized greedy
            // O(n)
            // O(1)
            auto ans = 0U;

            for (auto i = 0U; i < s.size() - 1; i += 2) {
                if (s[i] != s[i + 1]) {
                    ++ans;
                }
            }

            return ans;
        }
};
