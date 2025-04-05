#include <algorithm>
#include <vector>

using usize = std::size_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto lengthOfLIS(const std::vector<int> &nums
        ) const noexcept -> usize {
            // // 1. dynamic programming (dp)
            // // O(n^2)
            // // O(n)
            // const auto n = nums.size();
            // auto dp = std::vector(n, 1U);

            // for (auto i = 0U; i < n; ++i) {
            //     for (auto j = 0U; j < i; ++j) {
            //         if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
            //             dp[i] = dp[j] + 1;
            //         }
            //     }
            // }

            // return std::ranges::max(dp);

            // 2. greedy with binary search
            // O(n * log(n))
            // O(n)
            auto sub = std::vector<int>{};
            sub.reserve(nums.size());

            for (const auto num : nums) {
                if (sub.empty() || sub.back() < num) {
                    sub.push_back(num);
                } else {
                    auto it = std::ranges::lower_bound(sub, num);
                    *it = num;
                }
            }

            return sub.size();
        }
};
