#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto kthDistinct(
            const std::vector<std::string> &arr,
            const unsigned k
        ) -> std::string {
            auto freqs = std::unordered_map<std::string_view, unsigned>{};

            for (const auto &s : arr) {
                ++freqs[s];
            }

            auto i = 0U;

            for (const auto &s : arr) {
                if (freqs[s] == 1) {
                    ++i;

                    if (i == k) {
                        return s;
                    }
                }
            }

            return std::string{};
        }
};
