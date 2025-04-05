#include <algorithm>
#include <unordered_set>
#include <utility>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto lenLongestFibSubseq(
            const std::vector<int> &arr
        ) const noexcept -> std::size_t {
            const auto n = arr.size();
            const auto nums = std::unordered_set<int>{arr.begin(), arr.end()};
            auto ans = 0UZ;

            for (auto i = 0UZ; i < n; ++i) {
                for (auto j = i + 1; j < n; ++j) {
                    auto prev = arr[j];
                    auto curr = arr[i] + arr[j];
                    auto len = 2UZ;

                    while (nums.contains(curr)) {
                        prev = std::exchange(curr, curr + prev);
                        ++len;
                        ans = std::max(ans, len);
                    }
                }
            }

            return ans;
        }
};
