#include <algorithm>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto checkValidCuts(
            [[maybe_unused]] const uint n,
            std::vector<std::vector<int>> &rectangles
        ) const noexcept -> bool {
            return check_cuts(rectangles, 0) || check_cuts(rectangles, 1);
        }

    private:
        [[nodiscard]] constexpr auto check_cuts(
            std::vector<std::vector<int>> &rectangles,
            const uint dim
        ) const noexcept -> bool {
            std::ranges::sort(
                rectangles,
                [dim](const std::vector<int> &a, const std::vector<int> &b) {
                    return a[dim] < b[dim];
                }
            );

            auto gap_count = 0U;
            auto furthest_end = rectangles[0][dim + 2];

            for (auto i = 1UZ; i < rectangles.size(); ++i) {
                const auto &rect = rectangles[i];

                if (furthest_end <= rect[dim]) {
                    ++gap_count;
                }

                furthest_end = std::max(furthest_end, rect[dim + 2]);
            }

            return gap_count >= 2;
        }
};
