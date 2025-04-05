#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto lemonadeChange(
            const std::vector<int> &bills
        ) -> bool {
            auto fives = 0U;
            auto tens = 0U;

            for (const auto bill : bills) {
                if (bill == 5) {
                    ++fives;
                } else if (bill == 10) {
                    if (fives == 0) {
                        return false;
                    }

                    --fives;
                    ++tens;
                } else if (tens > 0 && fives > 0) {
                    --fives;
                    --tens;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }

            return true;
        }
};
