#include <numeric>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto doesValidArrayExist(
            const std::vector<int> &derived
        ) const noexcept -> bool {
            // // 1. simulation
            // // O(n)
            // // O(n)
            // const auto n = derived.size();
            // auto original = std::vector(n + 1, 0U);

            // for (auto i = 0U; i < n; ++i) {
            //     original[i + 1] = original[i] ^ derived[i];
            // }

            // if (original[0] == original[n]) {
            //     return true;
            // }

            // original[0] = 1;

            // for (auto i = 0U; i < n; ++i) {
            //     original[i + 1] = original[i] ^ derived[i];
            // }

            // return original[0] == original[n];

            // // 2. cumulative xor
            // // O(n)
            // // O(1)
            // auto xr = 0;

            // for (const auto e : derived) {
            //     xr ^= e;
            // }

            // return xr == 0;

            // 3. sum parity
            // O(n)
            // O(1)
            return std::accumulate(derived.begin(), derived.end(), 0) % 2 == 0;
        }
};
