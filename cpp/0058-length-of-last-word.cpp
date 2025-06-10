#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto lengthOfLastWord(
            const std::string &s
        ) const noexcept -> uint {
            auto i = s.size() - 1;

            while (i > 0 && s[i] == ' ') {
                --i;
            }

            auto ans = 0U;

            while (i > 0 && s[i] != ' ') {
                ++ans;
                --i;
            }

            if (i == 0 && s[0] != ' ') {
                return ans + 1;
            }

            return ans;
        }
};
