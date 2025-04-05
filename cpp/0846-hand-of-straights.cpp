#include <map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto isNStraightHand(
            const std::vector<int> &hand,
            const int group_size
        ) -> bool {
            auto counts = std::map<int, int>{};
            for (const auto card : hand) {
                ++counts[card];
            }

            for (const auto [start, start_freq] : counts) {
                if (start_freq > 0) {
                    for (auto i = start; i < start + group_size; ++i) {
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
