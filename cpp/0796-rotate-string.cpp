#include <algorithm>
#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto rotateString(
            std::string &s,
            const std::string &goal
        ) const noexcept -> bool {
            // // 1. brute force
            // // O(n^2)
            // // O(1)
            // const auto len = s.size();

            // for (auto shift = 0U; shift < len; ++shift) {
            //     std::ranges::rotate(s, s.begin() + 1);

            //     if (s == goal) {
            //         return true;
            //     }
            // }

            // return false;

            // // mine
            // // O(n^2)
            // // O(1)
            // const auto len = s.size();

            // for (auto shift = 0U; shift < len; ++shift) {
            //     auto found = true;

            //     for (auto i = 0U; i < len; ++i) {
            //         if (s[i] != goal[(i + shift) % len]) {
            //             found = false;

            //             break;
            //         }
            //     }

            //     if (found) {
            //         return true;
            //     }
            // }

            // return false;

            // // 2. concatenation check
            // // O(n)
            // // O(n)
            // if (s.size() != goal.size()) {
            //     return false;
            // }

            // s += s;

            // return s.contains(goal);

            // 3. knuth-morris-pratt (kmp)
            // O(n)
            // O(n)
            if (s.size() != goal.size()) {
                return false;
            }

            s += s;

            const auto &text = s;
            const auto &pattern = goal;
            const auto text_len = text.size();
            const auto pattern_len = pattern.size();

            // compute longest prefix suffix
            const auto lps = [&pattern, pattern_len]() {
                auto ans = std::vector(pattern_len, 0U);
                auto i = 1U;
                auto len = 0U;

                while (i < pattern_len) {
                    if (pattern[i] == pattern[len]) {
                        ++len;
                        ans[i] = len;
                        ++i;
                    } else if (len > 0) {
                        len = ans[len - 1];
                    } else {
                        ans[i] = 0;
                        ++i;
                    }
                }

                return ans;
            }();

            auto text_i = 0U;
            auto pattern_i = 0U;

            while (text_i < text_len) {
                if (text[text_i] == pattern[pattern_i]) {
                    ++text_i;
                    ++pattern_i;

                    if (pattern_i == pattern_len) {
                        return true;
                    }
                } else if (pattern_i > 0) {
                    pattern_i = lps[pattern_i - 1];
                } else {
                    ++text_i;
                }
            }

            return false;
        }
};
