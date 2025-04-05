#include <array>
#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumLength(const std::string &s
        ) const noexcept -> uint {
            // freq array (or hash map)
            // O(n)
            // O(k)
            auto freq = std::array<uint, 26>{};

            for (const auto c : s) {
                ++freq[static_cast<uint>(c - 'a')];
            }

            auto ans = 0U;

            for (auto i = 0U; i < 26; ++i) {
                if (freq[i] == 0) {
                    continue;
                }

                if (freq[i] % 2 == 0) {
                    ans += 2;
                } else {
                    ++ans;
                }
            }

            return ans;
        }
};
