#include <initializer_list>

class Solution {
    public:
        [[nodiscard]] constexpr auto isUgly(int n) -> bool {
            if (n == 0) {
                return false;
            }

            for (const auto i : {2, 3, 5}) {
                while (n % i == 0) {
                    n /= i;
                }
            }

            return n == 1;
        }
};
