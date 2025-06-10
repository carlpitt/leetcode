#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto canSortArray(
            const std::vector<int> &nums
        ) const noexcept -> bool {
            // // 1. bubble sort
            // // O(n**2)
            // // O(n)
            // const auto n = nums.size();
            // auto values = nums;

            // for (auto i = 0U; i < n; ++i) {
            //     for (auto j = 0U; j < n - i - 1; ++j) {
            //         if (values[j] <= values[j + 1]) {
            //             continue;
            //         }

            //         if (popcount(nums[j]) != popcount(nums[j + 1])) {
            //             return false;
            //         }

            //         std::swap(values[j], values[j + 1]);
            //     }
            // }

            // return true;

            // // 2. sortable segments
            // // O(n)
            // // O(1)
            // auto num_of_set_bits = popcount(nums[0]);
            // auto max_of_segment = nums[0];
            // auto min_of_segment = nums[0];
            // auto max_of_prev_segment = 0;

            // for (auto i = 1U; i < nums.size(); ++i) {
            //     const auto num = nums[i];

            //     if (popcount(num) == num_of_set_bits) {
            //         max_of_segment = std::max(max_of_segment, num);
            //         min_of_segment = std::min(min_of_segment, num);

            //         continue;
            //     }

            //     // num begins new segment
            //     if (min_of_segment < max_of_prev_segment) {
            //         return false;
            //     }

            //     max_of_prev_segment = max_of_segment;
            //     max_of_segment = num;
            //     min_of_segment = num;
            //     num_of_set_bits = popcount(num);
            // }

            // return min_of_segment > max_of_prev_segment;

            // // 3. forward and backward pass
            // // O(n)
            // // O(1)
            // const auto n = nums.size();

            // for (auto i = 0U; i < n - 1; ++i) {
            //     if (nums[i] <= nums[i + 1]) {
            //         continue;
            //     }

            //     if (popcount(nums[i]) != popcount(nums[i + 1])) {
            //         return false;
            //     }

            //     std::swap(nums[i], nums[i + 1]);
            // }

            // for (auto i = n - 1; i >= 1; --i) {
            //     if (nums[i] >= nums[i - 1]) {
            //         continue;
            //     }

            //     if (popcount(nums[i]) != popcount(nums[i - 1])) {
            //         return false;
            //     }

            //     std::swap(nums[i], nums[i - 1]);
            // }

            // return true;

            // mine
            // O(n)
            // O(1)
            auto prev_max = 0;
            auto curr_max = 0;
            auto curr_popcount = 0;

            for (const auto num : nums) {
                const auto num_popcount = std::popcount(static_cast<uint>(num));

                if (num_popcount == curr_popcount) {
                    curr_max = std::max(curr_max, num);
                } else {
                    // num begins new segment
                    prev_max = curr_max;
                    curr_max = num;
                    curr_popcount = num_popcount;
                }

                if (prev_max > num) {
                    return false;
                }
            }

            return true;
        }

    private:
        [[nodiscard]] constexpr auto popcount(const int num) const noexcept
            -> int {
            return std::popcount(static_cast<uint>(num));
        }

        [[nodiscard]] constexpr auto popcount(const uint num) const noexcept
            -> int {
            return std::popcount(num);
        }
};
