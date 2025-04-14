#include <cmath>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto countGoodTriplets(
            const std::vector<int> &arr,
            const int a,
            const int b,
            const int c
        ) const noexcept -> uint {
            const auto n = arr.size();
            auto ans = 0U;
            auto sum = std::vector(1001, 0U);

            for (auto j = 0U; j < n; ++j) {
                for (auto k = j + 1; k < n; ++k) {
                    if (std::abs(arr[j] - arr[k]) > b) {
                        continue;
                    }

                    const auto lj = arr[j] - a;
                    const auto rj = arr[j] + a;
                    const auto lk = arr[k] - c;
                    const auto rk = arr[k] + c;
                    const auto lef = std::max(std::max(0, lj), lk);
                    const auto rig = std::min(std::min(1000, rj), rk);

                    if (lef <= rig) {
                        ans += sum[static_cast<uint>(rig)];

                        if (lef != 0) {
                            ans -= sum[static_cast<uint>(lef) - 1];
                        }
                    }
                }

                for (auto k = static_cast<uint>(arr[j]); k <= 1000; ++k) {
                    ++sum[k];
                }
            }

            return ans;
        }
};
