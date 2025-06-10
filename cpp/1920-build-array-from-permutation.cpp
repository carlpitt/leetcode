#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto buildArray(
            std::vector<int> &nums
        ) const noexcept -> std::vector<int> & {
            // // 1.
            // // O(n)
            // // O(n)
            // const auto n = nums.size();
            // auto ans = std::vector(n, 0);

            // for (auto i = 0U; i < n; ++i) {
            //     ans[i] = nums[nums[i]];
            // }

            // return ans;

            // // 2.
            // // O(n)
            // // O(1)
            // const auto n = nums.size();

            // for (auto& num : nums) {
            //     num += n * (nums[num] % n);
            // }

            // for (auto& num : nums) {
            //     num /= n;
            // }

            // return nums;

            // 3.
            // O(n)
            // O(1)
            constexpr auto mask = 0b11'1111'1111;

            for (auto &num : nums) {
                num |= (nums[static_cast<uint>(num)] & mask) << 10;
            }

            for (auto &num : nums) {
                num >>= 10;
            }

            return nums;
        }
};
