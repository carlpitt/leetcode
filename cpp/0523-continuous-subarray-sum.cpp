#include <unordered_map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto
        checkSubarraySum(const std::vector<int> &nums, const int k) -> bool {
            auto totals = std::unordered_map<int, int>{{0, -1}};
            auto total = 0;
            for (auto i = 0; const auto n : nums) {
                // k != 0 check not needed
                total = (total + n) % k;
                const auto it = totals.insert({total, i}).first;
                if (i - it->second > 1) {
                    return true;
                }
                ++i;
            }
            return false;
        }
};
