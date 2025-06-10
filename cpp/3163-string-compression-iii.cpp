#include <string>

class Solution {
    public:
        [[nodiscard]] constexpr auto compressedString(
            const std::string &word
        ) const noexcept -> std::string {
            // string manipulation
            // O(n)
            // O(n) if you include output string
            const auto n = word.size();
            auto i = 0U;
            auto ans = std::string{};

            ans.reserve(2 * n);

            while (i < n) {
                auto group_len = char8_t{1};

                while (i + group_len < n && group_len < 9 &&
                       word[i] == word[i + group_len]) {
                    ++group_len;
                }

                ans += group_len + '0';
                ans += word[i];
                i += group_len;
            }

            return ans;
        }
};
