#include <vector>

class Solution {
    public:
        constexpr auto reverseString(std::vector<char> &s) const noexcept
            -> void {
            // std::ranges::reverse(s);

            const auto n = s.size();

            for (auto i = 0U; i < n / 2; ++i) {
                std::swap(s[i], s[n - i - 1]);
            }
        }
};
