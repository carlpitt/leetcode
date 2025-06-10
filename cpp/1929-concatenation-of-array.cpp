#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto getConcatenation(
            std::vector<int> &nums
        ) const noexcept -> std::vector<int> & {
            // O(n)
            // O(n)
            const auto n = nums.size();

            nums.reserve(2 * n);

            for (auto i = 0U; i < n; ++i) {
                nums.push_back(nums[i]);
            }

            return nums;
        }
};
