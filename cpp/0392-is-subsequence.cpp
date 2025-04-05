#include <array>
#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto isSubsequence(
            const std::string &s,
            const std::string &t
        ) const noexcept -> bool {
            // 1. 2 pointer
            // O(t.len())
            // O(1)
            if (s.empty()) {
                return true;
            }

            auto s_i = 0U;

            for (const auto c : t) {
                if (s[s_i] == c) {
                    ++s_i;

                    if (s_i == s.size()) {
                        return true;
                    }
                }
            }

            return false;

            // 2. dynamic programming
            // O(k * t.len() + s.len())
            // O(k * t.len())
            const auto t_len = t.size();
            auto next = std::vector(t_len + 1, std::array<uint, 26>{});

            for (auto i = 0U; i < t_len; ++i) {
                auto &entry = next[t_len - i - 1];
                entry = next[t_len - i];
                entry[static_cast<uint>(t[t_len - i - 1] - 'a')] = t_len - i;
            }

            auto i = 0U;

            for (const auto c : s) {
                const auto j = next[i][static_cast<uint>(c - 'a')];

                if (j == 0) {
                    return false;
                }

                i = j;
            }

            return true;
        }
};
