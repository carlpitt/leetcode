#include <vector>

class Solution {
    public:
        [[nodiscard]] auto findCenter(const std::vector<std::vector<int>> &edges
        ) -> int {
            if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
                return edges[0][0];
            }

            return edges[0][1];
        }
};
