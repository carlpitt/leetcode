#include <vector>

using uint = unsigned;

class Solution {
    public:
        constexpr auto merge(
            std::vector<int> &nums1,
            const uint m,
            const std::vector<int> &nums2,
            const uint n
        ) const noexcept -> void {
            // // 1. sort
            // // O((m + n) * log(m + n))
            // // O(log(m + n)) for sorting
            // for (auto i = 0U; i < n; ++i) {
            //     nums1[m + i] = nums2[i];
            // }

            // std::ranges::sort(nums1);

            // 2. 2 pointer
            // O(m + n)
            // O(1)
            auto i = 0U;
            auto j = 0U;

            while (j < n) {
                if (i < m && nums1[m - i - 1] > nums2[n - j - 1]) {
                    nums1[m + n - i - j - 1] = nums1[m - i - 1];
                    ++i;
                } else {
                    nums1[m + n - i - j - 1] = nums2[n - j - 1];
                    ++j;
                }
            }
        }
};
