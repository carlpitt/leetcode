#include <cstdint>
#include <queue>
#include <vector>

using uint = unsigned;
using i64 = std::int64_t;

class Solution {
    public:
        [[nodiscard]] auto maxKelements(std::vector<int> &nums, const uint k)
            const noexcept -> i64 {
            // priority queue
            // O(k * log(n) + n * log(n))
            // O(n)
            auto heap = std::priority_queue<int>{nums.begin(), nums.end()};
            auto ans = i64{0};

            for (auto i = 0U; i < k; ++i) {
                const auto curr_max = heap.top();
                ans += curr_max;

                if (curr_max == 1) {
                    return ans + k - i - 1;
                }

                heap.pop();
                // ceil(curr_max / 3)
                heap.push((curr_max + 2) / 3);
            }

            return ans;
        }
};
