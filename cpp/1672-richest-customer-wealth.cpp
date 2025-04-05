#include <numeric>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto maximumWealth(
            const std::vector<std::vector<int>> &accounts
        ) const noexcept -> int {
            // O(n**2)
            // O(1)
            return std::accumulate(
                accounts.begin(),
                accounts.end(),
                0,
                [](const auto sum, const auto &customer) {
                    return std::max(
                        sum,
                        std::reduce(customer.begin(), customer.end(), 0)
                    );
                }
            );
        }
};
