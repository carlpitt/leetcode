#include <algorithm>
#include <cstdint>
#include <vector>

using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto countFairPairs(
            std::vector<int> &nums,
            const int lower,
            const int upper
        ) const noexcept -> u64 {
            // 2 pointers
            // // O(n * log(n))
            // // O(log(n)) for std::ranges::sort()
            constexpr auto lower_bound = [](const std::vector<int> &v,
                                            const int value) noexcept {
                auto i = 0U;
                auto j = v.size() - 1;
                auto ans = u64{0};

                while (i < j) {
                    if (v[i] + v[j] < value) {
                        ans += j - i;
                        ++i;
                    } else {
                        --j;
                    }
                }

                return ans;
            };

            std::ranges::sort(nums);

            return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
        }
};
