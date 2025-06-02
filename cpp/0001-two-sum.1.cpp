#include <unordered_map>
#include <vector>

class Solution {
    public:
        static constexpr auto twoSum = [] [[nodiscard]] (
                                           const std::vector<int> &nums,
                                           const int target
                                       ) noexcept -> std::vector<int> {
            const auto n = nums.size();
            auto d = std::unordered_map<int, int>{};

            for (auto i = 0U; i < n; ++i) {
                d[nums[i]] = static_cast<int>(i);
            }

            for (auto i = 0U; i < n; ++i) {
                const auto complement = target - nums[i];

                if (d.contains(complement)) {
                    const auto e = d[complement];
                    const auto i_i = static_cast<int>(i);

                    if (e != i_i) {
                        return std::vector{static_cast<int>(i_i), e};
                    }
                }
            }

            return std::vector<int>{};
        };
};
