#include <algorithm>
#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto largestNumber(const std::vector<int> &nums
        ) const -> std::string {
            auto num_strs = std::vector<std::string>{};

            num_strs.reserve(nums.size());

            // TODO: convert to std::transform
            for (const auto num : nums) {
                num_strs.push_back(std::to_string(num));
            }

            std::ranges::sort(
                num_strs,
                [](const std::string &a, const std::string &b) {
                    return a + b > b + a;
                }
            );

            if (num_strs[0][0] == '0') {
                return num_strs[0];
            }

            auto ans = std::string{};

            ans.reserve(nums.size());

            for (const auto &num_str : num_strs) {
                ans += num_str;
            }

            return ans;
        }
};
