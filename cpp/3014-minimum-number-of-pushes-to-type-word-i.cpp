#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumPushes(const std::string &word)
            -> uint {
            const auto n = static_cast<uint>(word.size());
            const auto d = n / 8;

            return (d + 1) * (4 * d + n % 8);
        }
};
