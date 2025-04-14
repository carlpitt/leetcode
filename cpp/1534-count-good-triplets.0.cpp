#include <cmath>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto countGoodTriplets(
            const std::vector<int> &arr,
            const uint a,
            const uint b,
            const uint c
        ) const noexcept -> uint {
            const auto n = arr.size();
            auto ans = 0U;

            for (auto i = 0U; i < n; ++i) {
                for (auto j = i + 1; j < n; ++j) {
                    for (auto k = j + 1; k < n; ++k) {
                        if (static_cast<uint>(std::abs(arr[i] - arr[j])) <= a &&
                            static_cast<uint>(std::abs(arr[j] - arr[k])) <= b &&
                            static_cast<uint>(std::abs(arr[i] - arr[k])) <= c) {
                            ++ans;
                        }
                    }
                }
            }

            return ans;
        }
};
