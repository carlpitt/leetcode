#include <array>
#include <string>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto findMinDifference(
            const std::vector<std::string> &time_points
        ) const noexcept -> uint {
            constexpr auto min_per_hour = 60U;
            constexpr auto min_per_day = 24U * min_per_hour;
            auto minutes = std::array<bool, min_per_day>{};
            auto first = min_per_day;
            auto last = 0U;

            for (const auto &time : time_points) {
                const auto min =
                    min_per_hour * static_cast<uint>(
                                       10 * (time[0] - '0') + (time[1] - '0')
                                   ) +
                    static_cast<uint>(10 * (time[3] - '0') + time[4] - '0');

                if (minutes[min]) {
                    return 0;
                }

                minutes[min] = true;
                first = std::min(first, min);
                last = std::max(last, min);
            }

            auto ans = min_per_day;
            auto prev = first;

            for (auto i = first + 1; i <= last; ++i) {
                if (!minutes[i]) {
                    continue;
                }

                ans = std::min(ans, i - prev);
                prev = i;
            }

            return std::min(ans, min_per_day - last + first);
        }
};
