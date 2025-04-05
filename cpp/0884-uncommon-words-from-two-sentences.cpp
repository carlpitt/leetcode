#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto uncommonFromSentences(
            const std::string &s1,
            const std::string &s2
        ) const -> std::vector<std::string> {
            auto counter = std::unordered_map<std::string_view, uint>{};

            split_and_count(counter, s1);
            split_and_count(counter, s2);

            auto ans = std::vector<std::string>{};
            ans.reserve(counter.size());

            for (const auto [word, i] : counter) {
                if (i == 1) {
                    ans.emplace_back(word);
                }
            }

            return ans;
        }

    private:
        auto split_and_count(
            std::unordered_map<std::string_view, uint> &counter,
            const std::string &s
        ) const -> void {
            const auto n = s.size();
            auto prev = 0U;

            for (auto i = 0U; i < n; ++i) {
                if (s[i] == ' ') {
                    ++counter[std::string_view{&s[prev], i - prev}];
                    prev = i + 1;
                }
            }

            ++counter[std::string_view{&s[prev], n - prev}];
        }
};
