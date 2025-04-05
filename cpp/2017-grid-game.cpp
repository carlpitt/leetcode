#include <algorithm>
#include <cstdint>
#include <numeric>
#include <vector>

using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto gridGame(
            const std::vector<std::vector<int>> &grid
        ) const noexcept -> u64 {
            // prefix and suffix sum
            // O(n)
            // O(1)
            auto first_row_sum =
                std::accumulate(grid[0].begin(), grid[0].end(), u64{0});
            auto second_row_sum = u64{0};
            auto ans = std::numeric_limits<u64>::max();

            for (auto i = 0U; i < grid[0].size(); ++i) {
                first_row_sum -= static_cast<u64>(grid[0][i]);
                ans = std::min(ans, std::max(first_row_sum, second_row_sum));
                second_row_sum += static_cast<u64>(grid[1][i]);
            }

            return ans;
        }
};
