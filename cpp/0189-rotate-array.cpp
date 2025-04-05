#include <vector>

using uint = unsigned;

class Solution {
    public:
        constexpr auto rotate(std::vector<int> &nums, uint k) const noexcept
            -> void {
            // // 1. copy and rotate
            // // O(n)
            // // O(n)
            // const auto n = nums.size();
            // k %= n;
            // auto ans = std::vector(n, 0);

            // for (auto i = 0U; i < n; ++i) {
            //     ans[i] = nums[(n + i - k) % n];
            // }

            // for (auto i = 0U; i < n; ++i) {
            //     nums[i] = ans[i];
            // }

            // 2. reverse
            // O(n)
            // O(1)
            constexpr auto reverse =
                [](std::vector<int> &v, uint start, uint end) {
                    while (start < end) {
                        std::swap(v[start], v[end]);

                        ++start;
                        --end;
                    }
                };
            const auto n = static_cast<uint>(nums.size());
            k %= n;

            if (k == 0) {
                return;
            }

            reverse(nums, 0, n - 1);
            reverse(nums, 0, k - 1);
            reverse(nums, k, n - 1);
        }
};
