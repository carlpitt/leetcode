#include <algorithm>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto lenLongestFibSubseq(
            const std::vector<int> &arr
        ) const noexcept -> std::size_t {
            const auto n = arr.size();
            auto ans = 0UZ;
            auto dp = std::vector(n, std::vector(n, 0UZ));

            for (auto curr = 2UZ; curr < n; ++curr) {
                auto start = 0UZ;
                auto end = curr - 1;

                while (start < end) {
                    const auto pair_sum = arr[start] + arr[end];

                    if (pair_sum > arr[curr]) {
                        --end;
                    } else if (pair_sum < arr[curr]) {
                        ++start;
                    } else {
                        dp[end][curr] = dp[start][end] + 1;
                        ans = std::max(ans, dp[end][curr]);
                        --end;
                        ++start;
                    }
                }
            }

            if (ans == 0) {
                return 0;
            }

            return ans + 2;
        }
};
