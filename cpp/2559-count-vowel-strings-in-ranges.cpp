#include <string>
#include <unordered_set>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto vowelStrings(
            const std::vector<std::string> &words,
            const std::vector<std::vector<int>> &queries
        ) const noexcept -> std::vector<int> {
            // 1. prefix sum
            // O(m + n)
            // O(m)
            const auto vowels =
                std::unordered_set<char>{'a', 'e', 'i', 'o', 'u'};
            auto prefix_sum = std::vector(words.size(), 0);
            auto sum = 0;

            for (auto i = 0U; i < words.size(); ++i) {
                const auto &word = words[i];

                if (vowels.contains(word[0]) &&
                    vowels.contains(word[word.size() - 1])) {
                    ++sum;
                }

                prefix_sum[i] = sum;
            }

            auto ans = std::vector(queries.size(), 0);

            for (auto i = 0U; i < queries.size(); ++i) {
                const auto &query = queries[i];
                const auto left = static_cast<uint>(query[0]);
                const auto right = static_cast<uint>(query[1]);
                // ans[i] = prefix_sum[right] - (left == 0 ? 0 : prefix_sum[left
                // - 1]);
                ans[i] = prefix_sum[right];

                if (left >= 1) {
                    ans[i] -= prefix_sum[left - 1];
                }
            }

            return ans;
        }
};
