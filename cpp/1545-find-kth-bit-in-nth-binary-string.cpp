#include <algorithm>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findKthBit(
            [[maybe_unused]] const uint n,
            const uint k
        ) const noexcept -> char {
            // // mine
            // //
            // //
            // auto ans = "0"s;

            // // for (auto i = 0U; i < n; ++i) {
            // while (ans.size() < k) {
            //     auto prev = ans;

            //     for (auto& c : prev) {
            //         // if (c == '0') {
            //         //     c = '1';
            //         // } else {
            //         //     c = '0';
            //         // }
            //         c = !static_cast<bool>(c - '0') + '0';
            //     }

            //     std::ranges::reverse(prev);

            //     ans += '1';
            //     ans += prev;
            // }

            // return ans[k - 1];

            // // 1. brute force
            // // O(2**n)
            // // O(2**n)
            // auto ans = "0"s;

            // // for (auto i = 0U; i < n; ++i) {
            // while (ans.size() < k) {
            //     ans += '1';
            //     auto prev = ans;

            //     for (auto i = 0; i < prev.size() - 1; ++i) {
            //         if (prev[prev.size() - i - 2] == '0') {
            //             ans += '1';
            //         } else {
            //             ans += '0';
            //         }
            //     }
            // }

            // return ans[k - 1];

            // // 2. recursion
            // // O(n)
            // // O(n)
            // if (n == 1) {
            //     return '0';
            // }

            // // 2**n
            // const auto len = 1 << n;

            // if (k < len / 2) {
            //     return findKthBit(n - 1, k);
            // }

            // if (k == len / 2) {
            //     return '1';
            // }

            // if (findKthBit(n - 1, len - k) == '0') {
            //     return '1';
            // }

            // return '0';

            // // 3. iterative divide and conquer
            // // O(n)
            // // O(1)
            // auto invert_count = 0U;
            // // len of S_n is 2**n - 1
            // auto len = (1 << n) - 1;

            // while (k > 1) {
            //     if (k == len / 2 + 1) {
            //         if (invert_count % 2 == 0) {
            //             return '1';
            //         } else {
            //             return '0';
            //         }
            //     }

            //     if (k > len / 2) {
            //         k = len + 1 - k;
            //         ++invert_count;
            //     }

            //     len /= 2;
            // }

            // if (invert_count % 2 == 0) {
            //     return '0';
            // } else {
            //     return '1';
            // }

            // 4. bit manipulation
            // O(1)
            // O(1)
            const auto pos_in_section = k & -k;
            const auto is_in_inverted_part =
                (((k / pos_in_section) >> 1) & 1) == 1;
            const auto original_bit_is_one = (k & 1) == 0;

            if (is_in_inverted_part) {
                if (original_bit_is_one) {
                    return '0';
                }

                return '1';
            }

            if (original_bit_is_one) {
                return '1';
            }

            return '0';
        }
};
