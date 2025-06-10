#include <algorithm>
#include <unordered_map>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto majorityElement(
            const std::vector<int> &nums
        ) const noexcept -> int {
            // // 1. sort
            // // O(n * log(n))
            // // O(log(n)) for sort
            // look at std::nth_element()?
            // std::ranges::sort(nums);

            // return nums[nums.size() / 2];

            // // 2. hash map
            // // O(n)
            // // O(n)
            // auto map = std::unordered_map<int, uint>{};

            // for (const auto num : nums) {
            //     ++map[num];
            // }

            // for (const auto [num, freq] : map) {
            //     if (freq > nums.size() / 2) {
            //         return num;
            //     }
            // }

            // return 0;

            // 3. boyer-moore majority vote
            // O(n)
            // O(1)
            auto count = 0U;
            auto ans = 0;

            for (const auto num : nums) {
                if (count == 0) {
                    ans = num;
                }

                if (ans == num) {
                    ++count;
                } else {
                    --count;
                }
            }

            return ans;
        }
};
