#include <array>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto relativeSortArray(
            std::vector<int> &arr1,
            const std::vector<int> &arr2
        ) -> std::vector<int> {
            // auto counts = std::unordered_map<int, unsigned>{};
            auto counts = std::array<unsigned, 1001>{};
            for (const auto n : arr1) {
                ++counts[static_cast<unsigned>(n)];
            }

            auto i = 0U;

            for (const auto n : arr2) {
                auto &count = counts[static_cast<unsigned>(n)];
                while (count > 0) {
                    arr1[i] = n;
                    --count;
                    ++i;
                }
            }

            for (auto n = 0; auto &count : counts) {
                while (count > 0) {
                    arr1[i] = n;
                    --count;
                    ++i;
                }
                ++n;
            }

            return arr1;
        }
};
