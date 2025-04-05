#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto mostCommonWord(
            std::string &paragraph,
            const std::vector<std::string> &banned
        ) const -> std::string {
            const auto n = paragraph.size();
            auto prev = 0U;
            auto banned_set = std::unordered_set<std::string_view>{};

            for (const auto &word : banned) {
                banned_set.insert(word);
            }

            auto counter = std::unordered_map<std::string_view, uint>{};
            auto max_count = 0U;
            auto ans = std::string_view{};

            for (auto i = 0U; i <= n; ++i) {
                // not letter i.e. space or punctuation
                // in " !?',;."
                if (i == n || !is_alpha(paragraph[i])) {
                    if (i == prev) {
                        // prev = i + 1;
                        ++prev;

                        continue;
                    }

                    const auto word =
                        std::string_view{&paragraph[prev], i - prev};

                    if (banned_set.contains(word)) {
                        prev = i + 1;

                        continue;
                    }

                    auto &count = counter[word];
                    ++count;

                    if (count > max_count) {
                        max_count = count;
                        ans = word;
                    }

                    prev = i + 1;

                    continue;
                }

                auto &c = paragraph[i];

                if (c >= 'A' && c <= 'Z') {
                    c = c - 'A' + 'a';
                }
            }

            return std::string{ans};
        }

    private:
        [[nodiscard]] constexpr auto is_alpha(const char c) const noexcept
            -> bool {
            return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
        }
};
