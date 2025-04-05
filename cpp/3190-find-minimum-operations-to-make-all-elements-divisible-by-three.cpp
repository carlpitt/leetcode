#include <numeric>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumOperations(
            const std::vector<int> &nums
        ) const noexcept -> uint {
            return std::accumulate(
                nums.begin(),
                nums.end(),
                0U,
                [](const uint init, const int num) {
                    return init + static_cast<uint>(num % 3 != 0);
                }
            );
        }
};
