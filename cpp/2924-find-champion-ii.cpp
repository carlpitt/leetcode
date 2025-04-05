#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findChampion(
            const uint n,
            const std::vector<std::vector<int>> &edges
        ) const noexcept -> int {
            // indegree count
            // O(n + m)
            // O(n)
            auto lost = std::vector(n, false);

            for (const auto &edge : edges) {
                lost[static_cast<uint>(edge[1])] = true;
            }

            auto ans = -1;

            for (auto i = 0U; i < n; ++i) {
                if (!lost[i]) {
                    if (ans != -1) {
                        return -1;
                    }

                    ans = static_cast<int>(i);
                }
            }

            return ans;
        }
};
