#include <cstdint>
#include <vector>

using i64 = std::int64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto maxMatrixSum(
            const std::vector<std::vector<int>> &matrix
        ) const noexcept -> i64 {
            // journey from minus to plus
            // O(m * n)
            // O(1)
            auto ans = i64{0};
            auto min = 100'000;
            auto odd_negatives = false;

            for (const auto &row : matrix) {
                for (const auto val : row) {
                    if (val < 0) {
                        ans -= val;
                        min = std::min(min, -val);
                        odd_negatives = !odd_negatives;
                    } else {
                        ans += val;
                        min = std::min(min, val);
                    }
                }
            }

            if (odd_negatives) {
                return ans - 2 * min;
            }

            return ans;
        }
};
