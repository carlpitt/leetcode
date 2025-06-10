#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findNumbers(
            const std::vector<int> &nums
        ) const noexcept -> uint {
            auto ans = 0U;

            for (auto num : nums) {
                auto even_digits = true;

                while (num > 0) {
                    // toggle
                    even_digits ^= true;
                    num /= 10;
                }

                if (even_digits) {
                    ++ans;
                }
            }

            return ans;
        }
};
