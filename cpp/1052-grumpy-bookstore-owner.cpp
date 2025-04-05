#include <vector>

class Solution {
    public:
        [[nodiscard]] auto maxSatisfied(
            const std::vector<int> &customers,
            const std::vector<int> &grumpy,
            const unsigned minutes
        ) -> int {
            auto total = 0;
            auto max_diff = 0;

            for (auto i = 0U; i < minutes; ++i) {
                total += customers[i] * (1 - grumpy[i]);
                max_diff += customers[i] * grumpy[i];
            }

            auto diff = max_diff;

            for (auto i = minutes; i < customers.size(); ++i) {
                total += customers[i] * (1 - grumpy[i]);
                diff += customers[i] * grumpy[i] -
                        customers[i - minutes] * grumpy[i - minutes];
                max_diff = std::max(max_diff, diff);
            }

            return total + max_diff;
        }
};
