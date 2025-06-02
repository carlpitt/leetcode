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
                const auto num = nums[i];
                const auto complement = target - num;
                const auto i_i = static_cast<int>(i);

                if (d.contains(complement)) {
                    return std::vector{d[complement], i_i};
                }

                d[num] = i_i;
            }

            return std::vector<int>{};
        };
};
