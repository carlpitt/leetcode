#include <string>

class Solution {
    public:
        [[nodiscard]] constexpr auto isPalindrome(
            const std::string &s
        ) const noexcept -> bool {
            // // 1.
            // // O(n)
            // // O(n)
            // auto new_s = std::string{};

            // new_s.reserve(s.size());

            // for (const auto c : s) {
            //     if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
            //         new_s.push_back(c);
            //     } else if (c >= 'A' && c <= 'Z') {
            //         new_s.push_back(c - 'A' + 'a');
            //     }
            // }

            // const auto n = new_s.size();

            // for (auto i = 0U; i < n / 2; ++i) {
            //     if (new_s[i] != new_s[n - i - 1]) {
            //         return false;
            //     }
            // }

            // return true;

            // 2.
            // O(n)
            // O(1)
            constexpr auto is_uppercase = [](const char c) {
                return c >= 'A' && c <= 'Z';
            };
            constexpr auto is_alphanumeric = [is_uppercase](const char c) {
                return (c >= '0' && c <= '9') || is_uppercase(c) ||
                       (c >= 'a' && c <= 'z');
            };
            constexpr auto to_lowercase = [is_uppercase](const char c) {
                if (is_uppercase(c)) {
                    return static_cast<char>(c - 'A' + 'a');
                }

                return c;
            };
            auto i = 0U;
            auto j = s.size() - 1;

            while (i < j) {
                if (!is_alphanumeric(s[i])) {
                    ++i;

                    continue;
                }

                if (!is_alphanumeric(s[j])) {
                    --j;

                    continue;
                }

                if (to_lowercase(s[i]) != to_lowercase(s[j])) {
                    return false;
                }

                ++i;
                --j;
            }

            return true;
        }
};
