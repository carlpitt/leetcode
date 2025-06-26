#include <string>

using uint = unsigned;

class Solution {
    public:
        static constexpr auto longestSubsequence = [] [[nodiscard]] (
                                                       const std::string &s,
                                                       const uint k
                                                   ) noexcept -> uint {
            const auto len = s.size();
            const auto bits = static_cast<uint>(std::bit_width(k));
            auto ans = 0U;
            auto sum = 0U;

            for (auto i = 0UZ; i < len; ++i) {
                const char c = s[len - 1 - i];

                if (c == '0') {
                    ++ans;

                    continue;
                }

                if (i < bits && sum + (1U << i) <= k) {
                    sum += 1U << i;
                    ++ans;
                }
            }

            return ans;
        };
};
