#include <algorithm>
#include <unordered_map>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minSubarray(
            const std::vector<int> &nums,
            const uint p
        ) const noexcept -> int {
            // // 1. brute force (TLE)
            // // O(n^2)
            // // O(1)
            // const auto n = nums.size();
            // const auto total_sum = std::accumulate(nums.begin(), nums.end(),
            // 0U);

            // if (total_sum % p == 0) {
            //     return 0;
            // }

            // auto min_len = n;

            // for (auto start = 0UZ; start < n; ++start) {
            //     auto sub_sum = 0U;

            //     for (auto end = start; end < n; ++end) {
            //         sub_sum += nums[end];

            //         const auto remaining_sum = (total_sum - sub_sum) % p;

            //         if (remaining_sum == 0) {
            //             min_len = std::min(min_len, end - start + 1);
            //         }
            //     }
            // }

            // if (min_len == n) {
            //     return -1;
            // }

            // return min_len;

            // 2. prefix sum modulo
            // O(n)
            // O(n)
            const auto n = nums.size();
            const auto total_sum = [&nums, p]() {
                auto ans = 0U;

                for (const auto num : nums) {
                    ans = (ans + num) % p;
                }

                return ans;
            }();
            const auto target = total_sum % p;

            if (target == 0) {
                return 0;
            }

            auto mod_map = std::unordered_map<uint, int>{{0, -1}};
            auto curr_sum = 0U;
            auto min_len = n;

            for (auto i = 0UZ; i < n; ++i) {
                curr_sum = (curr_sum + nums[i]) % p;
                const auto needed = (curr_sum - target + p) % p;

                if (mod_map.contains(needed)) {
                    min_len = std::min(min_len, i - mod_map[needed]);
                }

                mod_map[curr_sum] = i;
            }

            if (min_len == n) {
                return -1;
            }

            return min_len;
        }
};
