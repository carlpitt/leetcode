#include <algorithm>
#include <ranges>
#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto countSeniors(
            const std::vector<std::string> &details
        ) -> unsigned {
            return static_cast<unsigned>(std::ranges::count_if(
                details,
                [](const std::string &s) noexcept {
                    // age > 60
                    return (s[11] - '0') * 10 + s[12] > 60 + '0';
                    // return s[11] == '6' && s[12] > '0' || s[11] > '6';
                }
            ));
        }
};
