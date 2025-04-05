#include <map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto
        isPossibleDivide(const std::vector<int> &nums, const int k) -> bool {
            auto counts = std::map<int, int>{};
            for (const auto card : nums) {
                ++counts[card];
            }

            for (const auto [start, start_freq] : counts) {
                if (start_freq > 0) {
                    for (auto i = start; i < start + k; ++i) {
                        counts[i] -= start_freq;
                        if (counts[i] < 0) {
                            return false;
                        }
                    }
                }
            }

            return true;
        }
};
