#include <array>
#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto checkInclusion(
            std::string &s1,
            const std::string &s2
        ) const noexcept -> bool {
            // // 2. sorting
            // // O((len_2 - len_1) * len_1 * log(len_1))
            // // O(len_1)
            // std::ranges::sort(s1);

            // for (auto i = 0U; i + s1.size() <= s2.size(); ++i) {
            //     auto t = s2.substr(i, s1.size());

            //     std::ranges::sort(t);

            //     if (s1 == t) {
            //         return true;
            //     }
            // }

            // return false;

            // // 4. array
            // // O(len_1 + (26 + len_1) * (len_2 - len_1))
            // // O(len_2 - len_1)
            // auto s1_arr = std::array<uint, 26>{};

            // for (const auto c : s1) {
            //     ++s1_arr[c - 'a'];
            // }

            // for (auto i = 0U; i + s1.size() <= s2.size(); ++i) {
            //     auto s2_arr = std::array<uint, 26>{};

            //     for (auto j = 0U; j < s1.size(); ++j) {
            //         ++s2_arr[s2[i + j] - 'a'];
            //     }

            //     if (s1_arr == s2_arr) {
            //         return true;
            //     }
            // }

            // return false;

            // // 5. sliding window
            // // O(len_1 + 26 * (len_2 - len_1)) == O(len_1 + (len_2 - len_1))
            // ==
            // // O(len_2)

            // // O(26 + 26) == O(1)
            // if (s1.size() > s2.size()) {
            //     return false;
            // }

            // auto s1_arr = std::array<uint, 26>{};
            // auto s2_arr = std::array<uint, 26>{};

            // for (auto i = 0U; i < s1.size(); ++i) {
            //     ++s1_arr[s1[i] - 'a'];
            //     ++s2_arr[s2[i] - 'a'];
            // }

            // for (auto i = 0U; i + s1.size() < s2.size(); ++i) {
            //     if (s1_arr == s2_arr) {
            //         return true;
            //     }

            //     ++s2_arr[s2[i + s1.size()] - 'a'];
            //     --s2_arr[s2[i] - 'a'];
            // }

            // return s1_arr == s2_arr;

            // 6. optimized sliding window
            // O(len_1 + (len_2 - len_1)) == O(len_2)
            // O(1)
            if (s1.size() > s2.size()) {
                return false;
            }

            auto s1_arr = std::array<uint, 26>{};
            auto s2_arr = std::array<uint, 26>{};

            for (auto i = 0U; i < s1.size(); ++i) {
                ++s1_arr[static_cast<uint>(s1[i] - 'a')];
                ++s2_arr[static_cast<uint>(s2[i] - 'a')];
            }

            auto count = 0U;

            for (auto i = 0U; i < 26; ++i) {
                if (s1_arr[i] == s2_arr[i]) {
                    ++count;
                }
            }

            for (auto i = 0U; i + s1.size() < s2.size(); ++i) {
                if (count == 26) {
                    return true;
                }

                const auto right = static_cast<uint>(s2[i + s1.size()] - 'a');
                const auto left = static_cast<uint>(s2[i] - 'a');
                ++s2_arr[right];

                if (s2_arr[right] == s1_arr[right]) {
                    ++count;
                } else if (s2_arr[right] == s1_arr[right] + 1) {
                    --count;
                }

                --s2_arr[left];

                if (s2_arr[left] == s1_arr[left]) {
                    ++count;
                } else if (s2_arr[left] == s1_arr[left] - 1) {
                    --count;
                }
            }

            return count == 26;
        }
};
