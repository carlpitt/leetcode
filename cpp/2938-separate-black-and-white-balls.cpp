#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumSteps(const std::string &s
        ) const noexcept -> uint {
            // // 1. 2 pointer
            // // O(n)
            // // O(1)
            // auto ans = 0U;
            // auto white_pos = 0U;

            // for (auto i = 0U; i < s.size(); ++i) {
            //     if (s[i] == '0') {
            //         ans += i - white_pos;
            //         ++white_pos;
            //     }
            // }

            // return ans;

            // 2. counter
            // O(n)
            // O(1)
            auto ans = 0U;
            auto black_balls = 0U;

            for (const auto c : s) {
                if (c == '0') {
                    ans += black_balls;
                } else {
                    ++black_balls;
                }
            }

            return ans;
        }
};
