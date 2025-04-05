#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto removeElement(
            std::vector<int> &nums,
            const int val
        ) const noexcept -> uint {
            // const auto n = nums.size();
            // const auto erased = std::erase(nums, val);

            // return n - erased;

            auto ans = 0U;

            for (auto i = 0U; i < nums.size(); ++i) {
                if (nums[i] != val) {
                    nums[ans] = nums[i];
                    ++ans;
                }
            }

            return ans;
        }
};
