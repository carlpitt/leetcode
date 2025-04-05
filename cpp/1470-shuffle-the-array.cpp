#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto shuffle(
            std::vector<int> &nums,
            const uint n
        ) const noexcept -> std::vector<int> & {
            // // 1.
            // // O(n)
            // // O(n) including output
            // auto ans = std::vector(2 * n, 0);

            // for (auto i = 0U; i < n; ++i) {
            //     ans[2 * i] = nums[i];
            //     ans[2 * i + 1] = nums[i + n];
            // }

            // return ans;

            // 2.
            // O(n)
            // O(1)
            auto i = n - 1;

            for (auto j = 2 * n - 1; j >= n; --j) {
                nums[j] <<= 10;
                nums[j] |= nums[i];
                --i;
            }

            i = 0;

            for (auto j = n; j < 2 * n; ++j) {
                nums[i] = nums[j] & 1023;
                nums[i + 1] = nums[j] >> 10;
                i += 2;
            }

            return nums;
        }
};
