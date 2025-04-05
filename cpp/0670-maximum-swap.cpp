#include <array>
#include <string>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto maximumSwap(const uint num) const noexcept
            -> uint {
            // // mine
            // //
            // //
            // auto i = num;
            // auto v = std::vector<uint>{};

            // while (i > 0) {
            //     v.push_back(i % 10);

            //     i /= 10;
            // }

            // const auto n = v.size();

            // for (auto i = 0U; i < n; ++i) {
            //     auto max = &v[0];

            //     for (auto j = 1U; j < n - i - 1; ++j) {
            //         if (v[j] > *max) {
            //             max = &v[j];
            //         }
            //     }

            //     if (*max > v[n - i - 1]) {
            //         std::swap(*max, v[n - i - 1]);

            //         break;
            //     }
            // }

            // auto ans = 0U;

            // for (auto i = 0U; i < n; ++i) {
            //     ans = 10 * ans + v[n - i - 1];
            // }

            // return ans;

            // // 1. brute force
            // // O(n^2)
            // // O(n)
            // auto num_str = std::to_string(num);
            // const auto n = num_str.size();
            // auto ans = num;

            // for (auto i = 0U; i < n; ++i) {
            //     for (auto j = i + 1; j < n; ++j) {
            //         std::swap(num_str[i], num_str[j]);

            //         ans = std::max(ans, std::stoi(num_str));

            //         std::swap(num_str[i], num_str[j]);
            //     }
            // }

            // return ans;

            // // 2. greedy 2-pass
            // // O(n)
            // // O(n)
            // auto num_str = std::to_string(num);
            // const auto n = num_str.size();
            // auto max_right_i = std::vector(n, 0U);
            // max_right_i[n - 1] = n - 1;

            // for (auto i = 0UZ; i < n - 1; ++i) {
            //     if (num_str[n - i - 2] > num_str[max_right_i[n - i - 1]]) {
            //         max_right_i[n - i - 2] = n - i - 2;
            //     } else {
            //         max_right_i[n - i - 2] = max_right_i[n - i - 1];
            //     }
            // }

            // for (auto i = 0UZ; i < n; ++i) {
            //     if (num_str[i] < num_str[max_right_i[i]]) {
            //         std::swap(num_str[i], num_str[max_right_i[i]]);

            //         return std::stoi(num_str);
            //     }
            // }

            // return num;

            // // 3. suboptimal greedy
            // // O(n)
            // // O(n)
            // auto num_str = std::to_string(num);
            // const auto n = num_str.size();
            // auto last_seen = std::array<int, 10>{};

            // last_seen.fill(-1);

            // for (auto i = 0UZ; i < n; ++i) {
            //     last_seen[num_str[i] - '0'] = i;
            // }

            // for (auto i = 0; i < n; ++i) {
            //     for (auto d = 9; d > num_str[i] - '0'; --d) {
            //         if (last_seen[d] > i) {
            //             std::swap(num_str[i], num_str[last_seen[d]]);

            //             return std::stoi(num_str);
            //         }
            //     }
            // }

            // return num;

            // // 4. space optimized greedy
            // // O(n)
            // // O(n)
            // auto num_str = std::to_string(num);
            // const auto n = num_str.size();
            // auto max_digit_i = -1;
            // auto swap_i1 = -1;
            // auto swap_i2 = -1;

            // for (auto i = 0UZ; i < n; ++i) {
            //     if (max_digit_i == -1 ||
            //         num_str[n - i - 1] > num_str[max_digit_i]) {
            //         max_digit_i = n - i - 1;
            //     } else if (num_str[n - i - 1] < num_str[max_digit_i]) {
            //         swap_i1 = n - i - 1;
            //         swap_i2 = max_digit_i;
            //     }
            // }

            // if (swap_i1 != -1 && swap_i2 != -1) {
            //     std::swap(num_str[swap_i1], num_str[swap_i2]);
            // }

            // return std::stoi(num_str);

            // truly optimized greedy
            // O(n)
            // O(1)
            auto remaining = num / 10;
            auto i = 1U;
            auto curr_max = num % 10;
            auto curr_max_i = 1U;
            auto diff = 0U;

            while (remaining > 0) {
                const auto curr_d = remaining % 10;
                remaining /= 10;
                i *= 10;

                if (curr_d < curr_max) {
                    diff = (curr_max - curr_d) * (i - curr_max_i);
                } else if (curr_d > curr_max) {
                    curr_max = curr_d;
                    curr_max_i = i;
                }
            }

            return num + diff;
        }
};
