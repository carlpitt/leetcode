#include <array>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto heightChecker(const std::vector<int> &heights)
            -> int {
            auto freqs = std::array<int, 101>{};
            for (const auto height : heights) {
                ++freqs[static_cast<unsigned>(height)];
            }

            auto curr = 1U;
            auto ans = 0;

            for (const auto height : heights) {
                while (freqs[curr] == 0) {
                    ++curr;
                }

                if (curr != static_cast<unsigned>(height)) {
                    ++ans;
                }

                --freqs[curr];
            }

            return ans;
        }
};
