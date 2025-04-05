#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto minHeightShelves(
            const std::vector<std::vector<int>> &books,
            const int shelf_width
        ) -> int {
            const auto n = books.size();
            auto dp = std::vector<int>(n + 1);
            dp[1] = books[0][1];

            for (auto i = 1U; i <= n; ++i) {
                auto width = books[i - 1][0];
                auto max_height = books[i - 1][1];
                dp[i] = dp[i - 1] + max_height;

                for (auto j = i - 1;
                     j > 0 && width + books[j - 1][0] <= shelf_width;
                     --j) {
                    width += books[j - 1][0];
                    max_height = std::max(max_height, books[j - 1][1]);
                    dp[i] = std::min(dp[i], dp[j - 1] + max_height);
                }
            }

            return dp[n];
        }
};
