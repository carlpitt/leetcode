#include <algorithm>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto countPairs(
            std::vector<int> &nums,
            const int target
        ) const noexcept -> uint {
            // // 1. brute force
            // // O(n**2)
            // // O(1)
            // const auto n = nums.size();
            // auto ans = 0U;

            // for (auto i = 0U; i < n; ++i) {
            //     for (auto j = i + 1; j < n; ++j) {
            //         if (i < j && nums[i] + nums[j] < target) {
            //             ++ans;
            //         }
            //     }
            // }

            // return ans;

            // 2. sort and 2 pointers
            // O(n * log(n))
            // O(log(n)) for std::ranges::sort()
            std::ranges::sort(nums);

            auto ans = 0U;
            auto i = 0U;
            auto j = nums.size() - 1;

            while (i < j) {
                if (nums[i] + nums[j] < target) {
                    ans += j - i;
                    ++i;
                } else {
                    --j;
                }
            }

            return ans;
        }
};
