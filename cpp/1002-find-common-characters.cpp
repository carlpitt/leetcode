#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto commonChars(const std::vector<std::string> &words)
            -> std::vector<std::string> {
            auto common = std::unordered_map<char, unsigned>{};
            for (const auto c : words[0]) {
                ++common[c];
            }

            for (auto i = 1U; i < words.size(); ++i) {
                auto count = std::unordered_map<char, unsigned>{};
                for (const auto c : words[i]) {
                    ++count[c];
                }

                for (auto &[c, freq] : common) {
                    freq = std::min(freq, count[c]);
                }
            }

            auto ans = std::vector<std::string>{};

            for (const auto [c, freq] : common) {
                for (auto i = 0U; i < freq; ++i) {
                    ans.emplace_back(1, c);
                }
            }
            return ans;
        }
};
