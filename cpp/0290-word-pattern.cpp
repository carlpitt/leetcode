#include <sstream>
#include <unordered_map>
#include <unordered_set>

class Solution {
    public:
        [[nodiscard]] auto
        wordPattern(const std::string &pattern, const std::string &s) -> bool {
            auto i = 0U;
            auto in = std::istringstream{s};
            auto word = std::string{};
            auto c_to_word = std::unordered_map<char, std::string>{};
            auto uniq_words = std::unordered_set<std::string>{};
            while (i < pattern.size() && in >> word) {
                const auto c = pattern[i];
                if (c_to_word.contains(c)) {
                    if (c_to_word[c] != word) {
                        return false;
                    }
                } else {
                    if (uniq_words.contains(word)) {
                        return false;
                    }
                    c_to_word[c] = word;
                    uniq_words.insert(word);
                }
                ++i;
            }

            return i == pattern.size() && !(in >> word);
        }
};
