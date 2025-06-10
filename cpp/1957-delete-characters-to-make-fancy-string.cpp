#include <string>

class Solution {
    public:
        [[nodiscard]] constexpr auto makeFancyString(
            std::string &s
        ) const noexcept -> std::string {
            // // 1. inserts chars in new string
            // // O(n)
            // // O(n)
            // auto prev = s[0];
            // auto freq = 1U;
            // auto ans = std::string{s[0]};

            // for (auto i = 1U; i < s.size(); ++i) {
            //     const auto c = s[i];

            //     if (c == prev) {
            //         ++freq;
            //     } else {
            //         prev = c;
            //         freq = 1;
            //     }

            //     if (freq < 3) {
            //         ans += c;
            //     }
            // }

            // return ans;

            // 2. in-place 2-pointer
            // O(n)
            // O(1)
            if (s.size() < 3) {
                return s;
            }

            auto j = 2U;

            for (auto i = 2U; i < s.size(); ++i) {
                if (s[i] != s[j - 2] || s[i] != s[j - 1]) {
                    s[j] = s[i];
                    ++j;
                }
            }

            s.resize(j);

            return s;
        }
};
