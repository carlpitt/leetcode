#include <map>
#include <string>
#include <string_view>
#include <unordered_map>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto maximumLength(const std::string_view s
        ) const noexcept -> int {
            // // my brute force
            // //
            // //
            // const auto n = s.size();

            // for (auto i = n - 2; i >= 1; --i) {
            //     auto freqs = std::unordered_map<std::string_view, uint>{};

            //     for (auto j = 0U; j < n - i + 1; ++j) {
            //         const auto sub = s.substr(j, i);
            //         auto all_same_c = true;

            //         for (auto k = 0U; k < i - 1; ++k) {
            //             if (sub[k] != sub[k + 1]) {
            //                 all_same_c = false;

            //                 break;
            //             }
            //         }

            //         if (!all_same_c) {
            //             continue;
            //         }

            //         auto& freq = freqs[sub];
            //         ++freq;

            //         if (freq == 3) {
            //             return i;
            //         }
            //     }
            // }

            // return -1;

            // // 1. brute force
            // // O(n**3)
            // // O(n**2)
            // const auto n = s.size();
            // auto count = std::unordered_map<std::string, uint>{};

            // for (auto start = 0U; start < n; ++start) {
            //     auto curr = std::string{};

            //     for (auto end = start; end < n; ++end) {
            //         if (!curr.empty() && curr.back() != s[end]) {
            //             break;
            //         }

            //         curr.push_back(s[end]);

            //         ++count[curr];
            //     }
            // }

            // auto ans = 0U;

            // for (const auto [s, freq] : count) {
            //     if (freq >= 3) {
            //         ans = std::max(ans, static_cast<uint>(s.size()));
            //     }
            // }

            // if (ans == 0) {
            //     return -1;
            // }

            // return ans;

            // 2. optimized hashing
            // O(n**2)
            // O(n**2)
            const auto n = s.size();
            auto count = std::map<std::pair<char, uint>, uint>{};
            auto substr_len = 0U;

            for (auto start = 0U; start < n; ++start) {
                const auto c = s[start];
                substr_len = 0;

                for (auto end = start; end < n; ++end) {
                    if (c != s[end]) {
                        break;
                    }

                    ++substr_len;
                    ++count[{c, substr_len}];
                }
            }

            auto ans = 0U;

            for (const auto [p, freq] : count) {
                if (freq >= 3) {
                    ans = std::max(ans, p.second);
                }
            }

            if (ans == 0) {
                return -1;
            }

            return static_cast<int>(ans);
        }
};
