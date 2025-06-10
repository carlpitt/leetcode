#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto maxProfit(
            const std::vector<int> &prices
        ) const noexcept -> int {
            // // 1. brute force (TLE)
            // // O(n**2)
            // // O(1)
            // const auto n = prices.size();
            // auto ans = 0;

            // for (auto i = 0U; i < n; ++i) {
            //     for (auto j = i + 1; j < n; ++j) {
            //         if (prices[j] > prices[i]) {
            //             ans = std::max(ans, prices[j] - prices[i]);
            //         }
            //     }
            // }

            // return ans;

            // 2. kadane's algo
            // O(n)
            // O(1)
            auto ans = 0;
            auto curr_max = 0;

            for (auto i = 1U; i < prices.size(); ++i) {
                curr_max = std::max(curr_max + prices[i] - prices[i - 1], 0);
                ans = std::max(ans, curr_max);
            }

            return ans;
        }
};
