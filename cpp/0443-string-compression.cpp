#include <string>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto compress(
            std::vector<char> &chars
        ) const noexcept -> uint {
            // O(n)
            // O(1)
            const auto n = chars.size();
            auto ans = 0U;
            auto i = 0U;

            while (i < n) {
                auto group_len = 1U;

                while (i + group_len < n && chars[i] == chars[i + group_len]) {
                    ++group_len;
                }

                chars[ans] = chars[i];
                ++ans;

                if (group_len > 1) {
                    for (const auto c : std::to_string(group_len)) {
                        chars[ans] = c;
                        ++ans;
                    }
                }

                i += group_len;
            }

            return ans;
        }
};
