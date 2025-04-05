#include <string>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto strStr(
            const std::string &haystack,
            const std::string &needle
        ) const noexcept -> int {
            // // 1. naive brute force
            // // O(haystack.len() * needle.len())
            // // O(1)
            // for (auto i = 0U; i + needle.size() <= haystack.size(); ++i) {
            //     auto j = 0U;

            //     while (j < needle.size()) {
            //         if (haystack[i + j] != needle[j]) {
            //             break;
            //         }

            //         ++j;
            //     }

            //     if (j == needle.size()) {
            //         return static_cast<int>(i);
            //     }
            // }

            // return -1;

            // 2. kmp
            // preprocess : compute longest prefix suffix table
            auto lps = std::vector(needle.size(), 0U);
            auto i = 1U;
            auto len = 0U;

            while (i < needle.size()) {
                if (needle[i] == needle[len]) {
                    ++len;
                    lps[i] = len;
                    ++i;
                } else if (len > 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    ++i;
                }
            }

            i = 0;
            auto j = 0U;

            while (i < haystack.size()) {
                if (haystack[i] == needle[j]) {
                    ++i;
                    ++j;
                }

                if (j == needle.size()) {
                    return static_cast<int>(i - j);
                }

                if (i < haystack.size() && haystack[i] != needle[j]) {
                    if (j > 0) {
                        j = lps[j - 1];
                    } else {
                        ++i;
                    }
                }
            }

            return -1;

            // // 3.
            // return haystack.find(needle);
        }
};
