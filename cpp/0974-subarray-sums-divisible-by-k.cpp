#include <unordered_map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto
        subarraysDivByK(const std::vector<int> &nums, const int k) -> int {
            auto prefix_sum = 0;
            // auto freqs = std::unordered_map<int, int>{{0, 1}};
            auto freqs = std::vector<int>(static_cast<std::size_t>(k));
            freqs[0] = 1;
            auto ans = 0;
            for (const auto n : nums) {
                prefix_sum = ((prefix_sum + n) % k + k) % k;
                const auto i = static_cast<std::size_t>(prefix_sum);
                ans += freqs[i];
                ++freqs[i];
            }

            return ans;
        }
};
