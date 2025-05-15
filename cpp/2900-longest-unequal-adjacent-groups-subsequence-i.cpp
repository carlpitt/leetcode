#include <string>
#include <vector>

class Solution {
    public:
        static constexpr auto getLongestSubsequence =
            [] [[nodiscard]] (
                const std::vector<std::string> &words,
                const std::vector<int> &groups
            ) noexcept -> std::vector<std::string> {
            const auto n = words.size();
            auto ans = std::vector{words[0]};

            for (auto i = 1U; i < n; ++i) {
                if (groups[i - 1] != groups[i]) {
                    ans.push_back(words[i]);
                }
            }

            return ans;
        };
};
