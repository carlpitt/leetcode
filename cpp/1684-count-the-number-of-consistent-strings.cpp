#include <algorithm>
#include <array>
#include <string>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto countConsistentStrings(
            const std::string &allowed,
            const std::vector<std::string> &words
        ) const noexcept -> uint {
            auto is_allowed = std::array<bool, 26>{};

            for (const auto c : allowed) {
                is_allowed[static_cast<uint>(c - 'a')] = true;
            }

            auto ans = 0U;

            for (const auto &word : words) {
                const auto is_consistent =
                    !std::ranges::any_of(word, [is_allowed](const char c) {
                        return !is_allowed[static_cast<uint>(c - 'a')];
                    });

                if (is_consistent) {
                    ++ans;
                }
            }

            return ans;
        }
};
