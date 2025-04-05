#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findChampion(
            const std::vector<std::vector<int>> &grid
        ) const noexcept -> uint {
            // // mine
            // //
            // //
            // auto ans = 0U;
            // auto found = false;

            // while (!found) {
            //     found = true;

            //     for (auto j = 0U; j < grid.size(); ++j) {
            //         if (j != ans && grid[ans][j] == 0) {
            //             ans = j;
            //             found = false;

            //             break;
            //         }
            //     }
            // }

            // return ans;

            //
            //
            //
            auto ans = 0U;

            for (auto j = 0U; j < grid.size(); ++j) {
                if (j != ans && grid[ans][j] == 0) {
                    ans = j;
                }
            }

            return ans;
        }
};
