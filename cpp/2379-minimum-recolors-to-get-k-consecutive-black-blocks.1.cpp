#include <limits>
#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumRecolors(
            const std::string &blocks,
            const uint k
        ) const noexcept -> uint {
            const auto n = blocks.size();
            auto num_white = 0U;
            auto left = 0U;
            auto ans = std::numeric_limits<uint>::max();

            for (auto right = 0U; right < n; ++right) {
                if (blocks[right] == 'W') {
                    ++num_white;
                }

                if (right - left + 1 < k) {
                    continue;
                }

                ans = std::min(ans, num_white);

                if (blocks[left] == 'W') {
                    --num_white;
                }

                ++left;
            }

            return ans;
        }
};
