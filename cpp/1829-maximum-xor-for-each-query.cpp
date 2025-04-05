#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto getMaximumXor(
            const std::vector<int> &nums,
            const int maximum_bit
        ) const noexcept -> std::vector<int> {
            // // 1. prefix array and bit masking
            // // O(n)
            // // O(n)
            // const auto n = nums.size();
            // const auto prefix_xor = [n, &nums]() {
            //     auto ans = std::vector(n, 0);
            //     ans[0] = nums[0];

            //     for (auto i = 1U; i < n; ++i) {
            //         ans[i] = ans[i - 1] ^ nums[i];
            //     }

            //     return ans;
            // }();
            // const auto mask = (1 << maximum_bit) - 1;
            // auto ans = std::vector(n, 0);

            // for (auto i = 0U; i < n; ++i) {
            //     const auto curr_xor = prefix_xor[n - i - 1];
            //     ans[i] = curr_xor ^ mask;
            // }

            // return ans;

            // // 2. optimized calculation and bit masking
            // // O(n)
            // // O(n) including output
            // const auto n = nums.size();
            // auto xor_product = 0;

            // for (const auto num : nums) {
            //     xor_product ^= num;
            // }

            // const auto mask = (1 << maximum_bit) - 1;
            // auto ans = std::vector(n, 0);

            // for (auto i = 0U; i < n; ++i) {
            //     ans[i] = xor_product ^ mask;
            //     // remove last element
            //     xor_product ^= nums[n - i - 1];
            // }

            // return ans;

            // one pass
            // O(n)
            // O(n) including output
            const auto n = nums.size();
            auto xr = (1 << maximum_bit) - 1;
            auto ans = std::vector(n, 0);

            for (auto i = 0U; i < n; ++i) {
                xr ^= nums[i];
                ans[n - i - 1] = xr;
            }

            return ans;
        }
};
