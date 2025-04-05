#include <array>
#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findTheLongestSubstring(
            const std::string &s
        ) const noexcept -> uint {
            auto prefix_xor = 0U;
            constexpr auto c_map = []() {
                auto ans = std::array<uint, 26>{};

                // ans[static_cast<uint>('a' - 'a')] = 1;
                ans[0] = 1;
                ans[static_cast<uint>('e' - 'a')] = 2;
                ans[static_cast<uint>('i' - 'a')] = 4;
                ans[static_cast<uint>('o' - 'a')] = 8;
                ans[static_cast<uint>('u' - 'a')] = 16;

                return ans;
            }();

            auto mp = std::array<int, 32>{};
            mp.fill(-1);

            auto ans = 0U;

            for (auto i = 0U; i < s.size(); ++i) {
                prefix_xor ^= c_map[static_cast<uint>(s[i] - 'a')];

                if (mp[prefix_xor] == -1 && prefix_xor > 0) {
                    mp[prefix_xor] = static_cast<int>(i);
                }

                ans = std::max(ans, i - static_cast<uint>(mp[prefix_xor]));
            }

            return ans;
        }
};
