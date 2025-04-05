#include <bit>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto countBits(const uint n) const noexcept
            -> std::vector<int> {
            // O(n)
            // O(n) if including output
            auto ans = std::vector(n + 1, 0);

            for (auto i = 1U; i <= n; ++i) {
                // ans[i] = std::popcount(i);
                ans[i] =
                    static_cast<int>(static_cast<uint>(ans[i >> 1]) + (i & 1));
            }

            return ans;
        }
};
