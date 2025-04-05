#include <cstdint>
#include <string>
#include <vector>

using uint = unsigned;
using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto shortestPalindrome(const std::string &s
        ) const -> std::string {
            // // brute force
            // const auto len = s.size();
            // const auto reversed_s = std::string{s.rbegin(), s.rend()};

            // for (auto i = 0U; i < len; ++i) {
            //     if (std::string_view{&s[0], len - i} ==
            //         std::string_view{&reversed_s[i]}) {
            //         return reversed_s.substr(0, i) + s;
            //     }
            // }

            // return reversed_s + s;

            // // 2 pointer

            // if (s.empty()) {
            //     return s;
            // }

            // const auto len = s.size();
            // auto left = 0U;

            // for (auto right = len - 1; right > 0; --right) {
            //     if (s[left] == s[right]) {
            //         ++left;
            //     }
            // }

            // if (s[left] == s[0]) {
            //     ++left;
            // }

            // if (left == len) {
            //     return s;
            // }

            // const auto non_palindrome_suffix = s.substr(left);
            // const auto reverse_suffix =
            // std::string{non_palindrome_suffix.rbegin(),
            //                                         non_palindrome_suffix.rend()};

            // return reverse_suffix + shortestPalindrome(s.substr(0, left)) +
            //        non_palindrome_suffix;

            // kmp
            const auto reversed_s = std::string{s.rbegin(), s.rend()};
            const auto combined = s + '#' + reversed_s;

            // build prefix table
            const auto n = combined.size();
            auto prefix_table = std::vector<uint>(n);
            auto len = 0U;

            for (auto i = 1U; i < n; ++i) {
                while (len > 0 && combined[i] != combined[len]) {
                    len = prefix_table[len - 1];
                }

                if (combined[i] == combined[len]) {
                    ++len;
                }

                prefix_table[i] = len;
            }

            const auto palindrome_len = prefix_table[combined.size() - 1];
            const auto suffix = reversed_s.substr(0, s.size() - palindrome_len);

            return suffix + s;

            // // rolling hash based
            // constexpr auto mod_val = 1'000'000'007U;
            // constexpr auto hash_base = 29U;
            // auto forward_hash = u64{0};
            // auto reverse_hash = u64{0};
            // auto power_val = u64{1};
            // auto palindrome_end_i = std::numeric_limits<uint>::max();

            // for (auto i = 0U; i < s.size(); ++i) {
            //     const auto c = s[i];

            //     forward_hash = (forward_hash * hash_base + (c - 'a' + 1)) %
            //     mod_val; reverse_hash = (reverse_hash + (c - 'a' + 1) *
            //     power_val) % mod_val; power_val = (power_val * hash_base) %
            //     mod_val;

            //     if (forward_hash == reverse_hash) {
            //         palindrome_end_i = i;
            //     }
            // }

            // auto reversed_suffix = s.substr(palindrome_end_i + 1);

            // std::ranges::reverse(reversed_suffix);

            // return reversed_suffix + s;

            // // manacher's
            // // see also z algorithm, z function?
            // if (s.empty()) {
            //     return s;
            // }

            // // preprocess str
            // auto modified = "^"s;

            // for (const auto c : s) {
            //     modified += '#';
            //     modified += c;
            // }

            // modified += "#$"sv;

            // const auto len = modified.size();
            // auto palindrome_radius = std::vector<uint>(len);
            // auto center = 0U;
            // auto right_boundary = 0U;
            // auto max_palindrome_len = 0U;

            // for (auto i = 1U; i < len - 1; ++i) {
            //     const auto mirror_i = 2 * center - i;

            //     if (right_boundary > i) {
            //         palindrome_radius[i] =
            //             std::min(palindrome_radius[mirror_i], right_boundary
            //             - i);
            //     }

            //     while (modified[i - 1 - palindrome_radius[i]] ==
            //            modified[i + 1 + palindrome_radius[i]]) {
            //         ++palindrome_radius[i];
            //     }

            //     if (i + palindrome_radius[i] > right_boundary) {
            //         center = i;
            //         right_boundary = i + palindrome_radius[i];
            //     }

            //     if (i - palindrome_radius[i] == 1) {
            //         max_palindrome_len =
            //             std::max(max_palindrome_len, palindrome_radius[i]);
            //     }
            // }

            // auto reversed_suffix = s.substr(max_palindrome_len);

            // std::ranges::reverse(reversed_suffix);

            // return reversed_suffix + s;
        }
};
