#include <array>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto countMaxOrSubsets(
            const std::vector<int> &nums
        ) const noexcept -> uint {
            // // 1. recursion
            // // O(2^n)
            // // O(n)
            // const auto max_or = [&nums]() {
            //     auto ans = 0U;

            //     for (const auto num : nums) {
            //         ans |= static_cast<uint>(num);
            //     }

            //     return ans;
            // }();

            // return count_subsets1(nums, 0, 0, max_or);

            // // 2. memoization
            // // O(n * max_of)
            // // O(n * max_of)
            // const auto max_or = [&nums]() {
            //     auto ans = 0U;

            //     for (const auto num : nums) {
            //         ans |= static_cast<uint>(num);
            //     }

            //     return ans;
            // }();
            // auto memo = std::vector(nums.size(), std::vector(max_or + 1, 0));

            // return count_subsets2(nums, 0, 0, max_or, memo);

            // // 3. bit manipulation
            // // O(n * 2^n)
            // // O(1)
            // const auto max_or = [&nums]() {
            //     auto ans = 0U;

            //     for (const auto num : nums) {
            //         ans |= static_cast<uint>(num);
            //     }

            //     return ans;
            // }();
            // const auto n = nums.size();
            // // 2^n
            // const auto total_subsets = 1U << n;
            // auto ans = 0U;

            // for (auto subset_mask = 0U; subset_mask < total_subsets;
            //      ++subset_mask) {
            //     auto curr_or = 0;

            //     for (auto i = 0U; i < n; ++i) {
            //         if (((subset_mask >> i) & 1) == 1) {
            //             curr_or |= nums[i];
            //         }
            //     }

            //     if (curr_or == max_or) {
            //         ++ans;
            //     }
            // }

            // return ans;

            // // 4. bit manipulation and dynamic programming
            // // O(n * max)
            // // O(2^17)
            // auto max = 0U;
            // // 2^17
            // auto dp = std::array<uint, 1 << 17>{1};

            // for (const auto num_i : nums) {
            //     const auto num = static_cast<uint>(num_i);

            //     for (auto i = 0U; i <= max; ++i) {
            //         dp[(max - i) | num] += dp[max - i];
            //     }

            //     max |= num;
            // }

            // return dp[max];

            // 5. optimized bit manipulation and dynamic programming
            // O(n * max)
            // O(1)
            const auto max_or = [&nums]() {
                auto ans = 0U;

                for (const auto num : nums) {
                    ans |= static_cast<uint>(num);
                }

                return ans;
            }();
            auto ans = 0U;

            for (auto i = max_or; i > 0; i = (i - 1) & max_or) {
                auto count = 0U;

                for (const auto num : nums) {
                    if ((num & i) == 0) {
                        ++count;
                    }
                }

                ans += (static_cast<uint>(std::popcount(i) % 2 == 0) * 2 - 1) *
                       ((1 << count) - 1);
            }

            return (1 << nums.size()) + ans - 1;
        }

    private:
        [[nodiscard]] constexpr auto count_subsets1(
            const std::vector<int> &nums,
            const uint i,
            const uint curr_or,
            const uint target_or
        ) const noexcept -> uint {
            if (i == nums.size()) {
                return uint{curr_or == target_or};
            }

            const auto count_without =
                count_subsets1(nums, i + 1, curr_or, target_or);
            const auto count_with = count_subsets1(
                nums,
                i + 1,
                curr_or | static_cast<uint>(nums[i]),
                target_or
            );

            return count_without + count_with;
        }

        [[nodiscard]] constexpr auto count_subsets2(
            const std::vector<int> &nums,
            const uint i,
            const uint curr_or,
            const uint target_or,
            std::vector<std::vector<uint>> &memo
        ) const noexcept -> uint {
            if (i == nums.size()) {
                return uint{curr_or == target_or};
            }

            if (memo[i][curr_or] != 0) {
                return memo[i][curr_or];
            }

            const auto count_without =
                count_subsets2(nums, i + 1, curr_or, target_or, memo);
            const auto count_with = count_subsets2(
                nums,
                i + 1,
                curr_or | static_cast<uint>(nums[i]),
                target_or,
                memo
            );
            memo[i][curr_or] = count_without + count_with;

            return memo[i][curr_or];
        }
};
