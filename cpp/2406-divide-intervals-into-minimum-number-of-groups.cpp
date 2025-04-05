#include <array>
#include <limits>
#include <map>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minGroups(
            const std::vector<std::vector<int>> &intervals
        ) const noexcept -> uint {
            // // 1. sorting or priority queue
            // // O(n * log(n))
            // // O(n)
            // auto intervals_with_end = std::vector<std::array<int, 2>>{};

            // for (const auto& interval : intervals) {
            //     intervals_with_end.push_back({interval[0], 1});
            //     intervals_with_end.push_back({interval[1] + 1, -1});
            // }

            // std::ranges::sort(intervals_with_end);

            // auto concurr_intervals = 0U;
            // auto ans = 0U;

            // for (const auto [_, val] : intervals_with_end) {
            //     concurr_intervals += val;
            //     ans = std::max(ans, concurr_intervals);
            // }

            // return ans;

            // // 2. line sweep with ordered container
            // // O(n * log(n))
            // // O(n)
            // auto point_to_count = std::map<int, int>{};

            // for (const auto& interval : intervals) {
            //     ++point_to_count[interval[0]];
            //     --point_to_count[interval[1] + 1];
            // }

            // auto concurr_intervals = 0U;
            // auto ans = 0U;

            // for (const auto [_, val] : point_to_count) {
            //     concurr_intervals += val;
            //     ans = std::max(ans, concurr_intervals);
            // }

            // return ans;

            // 3. line sweep without ordered container
            // O(n + k)
            // O(k)
            auto range_start = std::numeric_limits<int>::max();
            auto range_end = std::numeric_limits<int>::min();

            for (const auto &interval : intervals) {
                range_start = std::min(range_start, interval[0]);
                range_end = std::max(range_end, interval[1]);
            }

            auto point_to_count = std::vector(range_end + 2, 0);

            for (const auto &interval : intervals) {
                ++point_to_count[interval[0]];
                --point_to_count[interval[1] + 1];
            }

            auto concurr_intervals = 0U;
            auto ans = 0U;

            for (auto i = range_start; i <= range_end; ++i) {
                concurr_intervals += point_to_count[i];
                ans = std::max(ans, concurr_intervals);
            }

            return ans;
        }
};
