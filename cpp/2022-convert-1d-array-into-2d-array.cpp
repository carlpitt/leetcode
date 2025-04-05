#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto construct2DArray(
            const std::vector<int> &original,
            const uint m,
            const uint n
        ) -> std::vector<std::vector<int>> {
            if (m * n != original.size()) {
                return std::vector<std::vector<int>>{};
            }

            auto ans = std::vector(m, std::vector<int>(n));

            for (auto i = 0U; i < original.size(); ++i) {
                ans[i / n][i % n] = original[i];
            }

            return ans;
        }
};
