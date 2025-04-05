#include <array>
#include <string_view>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto maximumLength(const std::string_view s
        ) const noexcept -> int {
            // // 1. hashing
            // // O(n + c * n) == O(n + 26 * n) == O(n)
            // // O(c * n) == O(26 * n) == O(n)
            // const auto n = s.size();
            // auto prev_c = s[0];
            // auto substr_len = 1U;
            // auto freq = std::array<std::vector<uint>, 26>{};

            // freq.fill(std::vector(n + 1, 0U));

            // freq[s[0] - 'a'][1] = 1;

            // for (auto i = 1U; i < n; ++i) {
            //     const auto curr_c = s[i];

            //     if (curr_c == prev_c) {
            //         ++substr_len;
            //         ++freq[curr_c - 'a'][substr_len];
            //     } else {
            //         prev_c = curr_c;
            //         substr_len = 1;
            //         ++freq[curr_c - 'a'][1];
            //     }
            // }

            // auto ans = -1;

            // for (auto c_i = 0U; c_i < freq.size(); ++c_i) {
            //     for (auto len = n - 1; len >= 1; --len) {
            //         freq[c_i][len] += freq[c_i][len + 1];

            //         if (freq[c_i][len] >= 3) {
            //             ans = std::max(ans, static_cast<int>(len));

            //             break;
            //         }
            //     }
            // }

            // return ans;

            // 2. store 3 max substr lengths
            // O(c * k + n * k) == O(k * (c + n)) == O(3 * (26 + n)) == O(n)
            // O(c * k) == O(26 * 3) == O(1)
            constexpr auto min = []<typename T>(T &a, T &b, T &c) -> T & {
                // return std::min(std::min(a, b), c);
                // return a < (b < c ? b : c) ? a : b < c ? b : c;
                if (a < b) {
                    if (a < c) {
                        return a;
                    }

                    return c;
                }

                if (b < c) {
                    return b;
                }

                return c;
            };
            auto prev_c = s[0];
            auto substr_len = 0;
            auto substr_lens = std::array<std::array<int, 3>, 26>{};

            substr_lens.fill(std::array{-1, -1, -1});

            for (const auto c : s) {
                if (c == prev_c) {
                    ++substr_len;
                } else {
                    substr_len = 1;
                    prev_c = c;
                }

                auto &min_len =
                    min(substr_lens[static_cast<uint>(c - 'a')][0],
                        substr_lens[static_cast<uint>(c - 'a')][1],
                        substr_lens[static_cast<uint>(c - 'a')][2]);

                min_len = std::max(min_len, substr_len);
            }

            auto ans = -1;

            for (auto c = 'a'; c <= 'z'; ++c) {
                ans = std::max(
                    ans,
                    min(substr_lens[static_cast<uint>(c - 'a')][0],
                        substr_lens[static_cast<uint>(c - 'a')][1],
                        substr_lens[static_cast<uint>(c - 'a')][2])
                );
            }

            return ans;
        }
};
