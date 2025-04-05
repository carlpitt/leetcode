#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findLengthOfShortestSubarray(
            const std::vector<int> &arr
        ) const noexcept -> uint {
            // 2 pointers
            // O(n)
            // O(1)
            const auto n = static_cast<uint>(arr.size());
            auto j = n - 1;

            while (j > 0 && arr[j - 1] <= arr[j]) {
                --j;
            }

            auto ans = j;
            auto i = 0U;
            while (i < j && (i == 0 || arr[i - 1] <= arr[i])) {
                while (j < n && arr[i] > arr[j]) {
                    ++j;
                }

                ans = std::min(ans, j - i - 1);
                ++i;
            }

            return ans;
        }
};
