#include <algorithm>
#include <array>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto frequencySort(std::vector<int> &nums)
            -> std::vector<int> & {
            auto freq = std::array<uint, 201>{};

            for (const auto n : nums) {
                ++freq[static_cast<uint>(n + 100)];
            }

            std::ranges::sort(nums, [freq](const int a, const int b) {
                const auto a_u = static_cast<uint>(a + 100);
                const auto b_u = static_cast<uint>(b + 100);

                return freq[a_u] < freq[b_u] ||
                       (a_u > b_u && freq[a_u] == freq[b_u]);
            });

            return nums;
        }
};
