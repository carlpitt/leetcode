#include <algorithm>
#include <string>
#include <unordered_set>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto numJewelsInStones(
            const std::string &jewels,
            const std::string &stones
        ) const noexcept -> uint {
            const auto jewel_set =
                std::unordered_set<char>{jewels.begin(), jewels.end()};

            return static_cast<uint>(
                std::ranges::count_if(stones, [&jewel_set](const char stone) {
                    return jewel_set.contains(stone);
                })
            );
        }
};
