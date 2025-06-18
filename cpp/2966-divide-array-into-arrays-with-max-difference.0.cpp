#include <algorithm>
#include <vector>

class Solution {
    public:
        static constexpr auto divideArray =
            [] [[nodiscard]] (std::vector<int> & nums, const int k) noexcept
            -> std::vector<std::vector<int>> {
            const auto n = nums.size();
            auto ans = std::vector(n / 3, std::vector(3, 0));

            std::ranges::sort(nums);

            for (auto i = 0U; i < n / 3; ++i) {
                if (nums[3 * i + 2] - nums[3 * i] > k) {
                    return std::vector<std::vector<int>>{};
                }

                for (auto j = 0U; j < 3; ++j) {
                    ans[i][j] = nums[3 * i + j];
                }
            }

            return ans;
        };
};
