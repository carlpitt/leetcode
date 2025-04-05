#include <cstdint>
#include <vector>

using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto mostPoints(
            const std::vector<std::vector<int>> &questions
        ) const noexcept -> u64 {
            const auto n = questions.size();
            auto dp = std::vector(n + 1, u64{0});

            for (auto i = n - 1; i > 0; --i) {
                const auto points = static_cast<std::size_t>(questions[i][0]);
                const auto jump = static_cast<std::size_t>(questions[i][1]);
                dp[i] =
                    std::max(points + dp[std::min(jump + i + 1, n)], dp[i + 1]);
            }

            const auto points = static_cast<std::size_t>(questions[0][0]);
            const auto jump = static_cast<std::size_t>(questions[0][1]);

            return std::max(points + dp[std::min(jump + 1, n)], dp[1]);
        }
};
