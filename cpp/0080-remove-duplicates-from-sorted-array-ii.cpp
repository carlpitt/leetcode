#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto removeDuplicates(std::vector<int> &nums
        ) const noexcept -> uint {
            auto ans = 0U;

            for (const auto num : nums) {
                if (ans < 2 || nums[ans - 2] < num) {
                    nums[ans] = num;
                    ++ans;
                }
            }

            return ans;
        }
};
