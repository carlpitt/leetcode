#include <queue>
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
            auto block_q = std::queue<char>{};

            for (auto i = 0UZ; i < k; ++i) {
                const auto c = blocks[i];

                if (c == 'W') {
                    ++num_white;
                }

                block_q.push(c);
            }

            auto ans = num_white;

            for (auto i = k; i < n; ++i) {
                if (block_q.front() == 'W') {
                    --num_white;
                }

                block_q.pop();

                if (blocks[i] == 'W') {
                    ++num_white;
                }

                block_q.push(blocks[i]);

                ans = std::min(ans, num_white);
            }

            return ans;
        }
};
