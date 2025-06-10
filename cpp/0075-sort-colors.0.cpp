#include <array>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        static constexpr auto sortColors =
            [](std::vector<int> &nums) noexcept -> void {
            const auto n = nums.size();
            auto f = std::array<uint, 3>{};

            for (auto i = 0U; i < n; ++i) {
                ++f[static_cast<uint>(nums[i])];
            }

            for (auto i = 0U; i < f[0]; ++i) {
                nums[i] = 0;
            }

            for (auto i = f[0]; i < f[0] + f[1]; ++i) {
                nums[i] = 1;
            }

            for (auto i = f[0] + f[1]; i < n; ++i) {
                nums[i] = 2;
            }
        };
};
