#include <vector>

class Solution {
    public:
        [[nodiscard]] auto
        numberOfSubarrays(const std::vector<int> &nums, int k) -> int {
            auto ans = 0;
            auto evens = 0;
            auto i = 0U;

            for (const auto num : nums) {
                if (num % 2 == 1) {
                    k -= 1;
                    evens = 0;
                }

                while (k == 0) {
                    k += nums[i] % 2;
                    i += 1;
                    evens += 1;
                }

                ans += evens;
            }

            return ans;
        }
};
