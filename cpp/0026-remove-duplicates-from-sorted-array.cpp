#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto removeDuplicates(
            std::vector<int> &nums
        ) const noexcept -> uint {
            auto ans = 1U;

            for (auto i = 1U; i < nums.size(); ++i) {
                if (nums[i - 1] != nums[i]) {
                    nums[ans] = nums[i];
                    ++ans;
                }
            }

            return ans;
        }
};
