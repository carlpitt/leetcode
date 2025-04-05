#include <algorithm>
#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto sortPeople(
            std::vector<std::string> &names,
            const std::vector<int> &heights
        ) -> std::vector<std::string> & {
            const auto n = names.size();
            auto pairs = std::vector<std::pair<int, std::string>>(n);

            for (auto i = 0U; i < n; ++i) {
                pairs[i] = {heights[i], names[i]};
            }

            std::sort(pairs.begin(), pairs.end(), std::greater<>());

            for (auto i = 0U; i < n; ++i) {
                names[i] = pairs[i].second;
            }

            return names;
        }
};
